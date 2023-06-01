#include "Rover.hh"
#include "Matrix3D.hh"
#include <fstream>


Rover::Rover(const char* sNameOfFile_ModelBlock, const char* sObjectName, int ColourID, 
    Vector3D Scale, Vector3D Position,
    double Angle, double Velocity, double Distance)
    {
        _NameOfFile_ModelBlock =sNameOfFile_ModelBlock;
        _ColourID=ColourID;
        _ObjectName = sObjectName;
        _NameOfFile_DrawBlock = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
        _NameOfFile_DrawBlock += "/";
        _NameOfFile_DrawBlock += sObjectName;
        _NameOfFile_DrawBlock += ".dat";
        _Scale = Scale;
        _Position = Position;
        _RotationAngle=Angle;
        _RotMatrix.FillRotationZ(_RotationAngle);
        _Velocity = Velocity;
        _Distance=Distance;
    }
void Rover::RotateRover(double Angle){
    _RotationAngle += Angle;
     while(_RotationAngle>=360) _RotationAngle-=360;
     while(_RotationAngle<=-360) _RotationAngle+=360;
    _RotMatrix.FillRotationZ(_RotationAngle);
}
void Rover::MoveRover(double Distance){
    Matrix3D rotacja;
    Vector3D przes;
    przes[1] = 1;
    rotacja.FillRotationZ(_RotationAngle);
    przes=rotacja*przes;
    _Position=_Position + przes*Distance;
    Count_and_save_tops();
}

CollisionType Rover::IsCollision(const std::shared_ptr<Rover>& Obj_ptr)const {
  if(_Contour.IsImposed(Obj_ptr->ReturnContour()))
    return CollisionType::CT_Collision;
  return CollisionType::CT_NoCollision;
}

void Rover::RoverState()const{
  std::cout<<std::endl<<"Aktywny Lazik"<<std::endl;
  std::cout<<"Nazwa: "<<_ObjectName<<std::endl;
  std::cout<<"Polozenie(x,y,z): "<<_Position[0]<<" "<<_Position[1]<<" "<<_Position[2]<<std::endl;
  std::cout<<"Orientacja [st]: "<<_RotationAngle<<std::endl;
}