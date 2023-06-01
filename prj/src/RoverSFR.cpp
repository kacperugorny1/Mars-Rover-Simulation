#include "RoverSFR.hh"

CollisionType RoverSFR::IsCollision(const std::shared_ptr<Rover>& Obj_ptr)const {
  if(_Contour.IsImposed(Obj_ptr->ReturnContour()))
    return CollisionType::CT_Collision;
  return CollisionType::CT_NoCollision;
}

void RoverSFR::DisplaySampleList()const{
    int x=0;
    std::cout<<"Zebrane Probki"<<std::endl;
    if(SampleList.size()==0){
        std::cout<<"Brak probek"<<std::endl<<std::endl;
        return;
    }
    for(std::shared_ptr<RegSample> RegSample_ptr:SampleList){
        ++x;
        std::cout<<x<<". "<<RegSample_ptr->ReturnObjectName()<<std::endl;
       }
    std::cout<<std::endl;
    }


void RoverSFR::AddSampleToList(std::list<std::shared_ptr<Object>>& from,std::list<std::shared_ptr<Object>>::const_iterator what){
    SampleList.push_front(std::static_pointer_cast<RegSample>(*what));
    from.erase(what);
    SampleList.front()->ReturnPosition() = _Position;
    SampleList.front()->ReturnPosition()[2]=(SampleList.size()-1)*2+10;
    SampleList.front()->ReturnRotMatrix() =_RotMatrix;
    SampleList.front()->Count_and_save_tops();
}

void RoverSFR::MoveRover(double Distance){
    Matrix3D rotacja;
    Vector3D przes;
    przes[1] = 1;
    rotacja.FillRotationZ(_RotationAngle);
    przes=rotacja*przes;
    _Position=_Position + przes*Distance;
    Count_and_save_tops();
    for(auto x: SampleList){
      x->ReturnPosition()[0] = _Position[0];
      x->ReturnPosition()[1] = _Position[1];
      x->Count_and_save_tops();
    }
}

void RoverSFR::RotateRover(double Angle){
    _RotationAngle += Angle;
     while(_RotationAngle>=360) _RotationAngle-=360;
     while(_RotationAngle<=-360) _RotationAngle+=360;
    _RotMatrix.FillRotationZ(_RotationAngle);
    for(auto x: SampleList){
      x->ReturnRotMatrix()=_RotMatrix;
      x->Count_and_save_tops();
    }
}

void RoverSFR::RoverState()const {
  Rover::RoverState();
  DisplaySampleList();
}
