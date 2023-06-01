#include <cmath>
#include <Matrix3D.hh>




void Matrix3D::FillRotationX(double theta){
    theta = theta*M_PI/180;
    value[0][0] = 1;
    value[1][1] = cos(theta);
    value[1][2] = -sin(theta);
    value[2][1] = sin(theta);
    value[2][2] = cos(theta);        
}   
void Matrix3D::FillRotationY(double theta){
    theta = theta*M_PI/180;
    value[1][1] = 1;
    value[0][0] = cos(theta);
    value[2][0] = -sin(theta);
    value[0][2] = sin(theta);
    value[2][2] = cos(theta);        
} 
void Matrix3D::FillRotationZ(double theta){
    theta = theta*M_PI/180;
    value[2][2] = 1;
    value[0][0] = cos(theta);
    value[0][1] = -sin(theta);
    value[1][0] = sin(theta);
    value[1][1] = cos(theta);        
}   