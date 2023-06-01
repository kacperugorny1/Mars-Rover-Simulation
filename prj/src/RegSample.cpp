#include "RegSample.hh"
#include "Kolory.hh"
#include <cmath>


RegSample::RegSample( const char*  sObjectName,
		        Vector3D scale,
            Vector3D Position)
		    {
    _NameOfFile_ModelBlock = "../bryly_wzorcowe/szescian2.dat";
    _ColourID = Kolor_Czerwony;
    _ObjectName = sObjectName;
    _NameOfFile_DrawBlock = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
    _NameOfFile_DrawBlock += "/";
    _NameOfFile_DrawBlock += sObjectName;
    _NameOfFile_DrawBlock += ".dat";
    _Scale = scale;
    _Position = Position;
    _RotMatrix.FillRotationZ(0);
    }


CollisionType RegSample::IsCollision(const std::shared_ptr<Rover>& x)const{
    Matrix3D Orient;
    double dist;
    double sin;
    Vector3D KierunkowyLazika = {0,1,0},KierunkowyLazikDoProbki = {_Position[0]-x->returnPosition()[0],_Position[1]-x->returnPosition()[1],0};
    if(!_Contour.IsImposed(x->ReturnContour()))  //gdy sie nie przecina No collision
      return CollisionType::CT_NoCollision;
    if(x->ReturnType()==ObjectType::RoverSFRT) // gdy kolizja z lazikiem SFR to zwroc CT_CanCollect
      return CollisionType::CT_CanCollect;
    if(_Position == x->returnPosition())      
      return CollisionType::CT_RunOverSample;
    Orient.FillRotationZ(x->returnAngle());
    KierunkowyLazika = Orient*KierunkowyLazika;
    dist = sqrt(pow((x->returnPosition()[0]-_Position[0]),2)+pow((x->returnPosition()[1]-_Position[1]),2));
    sin = sqrt(1-pow(KierunkowyLazika*KierunkowyLazikDoProbki/dist,2));
    if(sin*dist<=0.2*20)
      return CollisionType::CT_RunOverSample;
    return CollisionType::CT_Collision;
}
