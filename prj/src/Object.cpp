#include <iostream>
#include <fstream>
#include "Object.hh"



using namespace std;

Object::Object( const char*  sNameOfFile_ModelBlock,
		        const char*  sObjectName,
		        int          ColourID,
            Vector3D scale,
            Vector3D Position
		       ):
  _NameOfFile_ModelBlock(sNameOfFile_ModelBlock), _ColourID(ColourID)
{
  _ObjectName = sObjectName;
  _NameOfFile_DrawBlock = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NameOfFile_DrawBlock += "/";
  _NameOfFile_DrawBlock += sObjectName;
  _NameOfFile_DrawBlock += ".dat";
  _Scale = scale;
  _Position = Position;
  _RotMatrix.FillRotationZ(0);
}



bool Object::Count_and_save_tops() 
{
  ifstream  StrmWe(_NameOfFile_ModelBlock);
  ofstream  StrmWy(_NameOfFile_DrawBlock);

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    cerr << endl << "Nie mozna otworzyc jednego z plikow:" << endl
	 << "    " << _NameOfFile_ModelBlock << endl
	 << "    " << _NameOfFile_DrawBlock << endl
	 << endl;
    return false;
  }
  if(!Count_and_save_tops(StrmWe,StrmWy))
    return false;
  return true;
}


bool Object::Count_and_save_tops(std::istream& StrmIn,std::ostream & StrmOut){
  Vector3D Wsp;
  int Indeks_Wiersza = 0;
  int i=0;
  StrmIn >> Wsp;
  Vector2D &LD = _Contour.ReturnLDvect();
  Vector2D &RU = _Contour.ReturnRUvect();


  if (StrmIn.fail())return false;
  
  do {
    Wsp[0] = Wsp[0]*_Scale[0];
    Wsp[1] = Wsp[1]*_Scale[1];    
    Wsp[2] = Wsp[2]*_Scale[2];
    Wsp = _RotMatrix*Wsp;
    Wsp = Wsp+_Position;
    StrmOut << Wsp[0] << " " << Wsp[1] << " " << Wsp[2] << endl;
   
   
    if(i==0){
      LD[0] = Wsp[0];
      LD[1] = Wsp[1];
      RU[0] = Wsp[0];
      RU[1] = Wsp[1];
    }
    else{
      if(Wsp[0]<LD[0])
      LD[0] = Wsp[0];

      if(Wsp[1]<LD[1])
      LD[1] = Wsp[1];

      if(Wsp[0]>RU[0])
      RU[0] = Wsp[0];

      if(Wsp[1]>RU[1])
      RU[1] = Wsp[1];
    }

    ++Indeks_Wiersza;
    ++i;

    if (Indeks_Wiersza >= 4) {
      StrmOut << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmIn >> Wsp;
    
  } while (!StrmIn.fail());

  if (!StrmIn.eof()) return false;

  return Indeks_Wiersza == 0 && !StrmOut.fail();

}

