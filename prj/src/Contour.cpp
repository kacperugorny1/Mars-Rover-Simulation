#include "Contour.hh"



bool Contour::IsImposed(Contour x) const{
    if(RightUp[0]<x.LeftDown[0]||LeftDown[0]>x.RightUp[0])
        return false;
    if(RightUp[1]<x.LeftDown[1]||LeftDown[1]>x.RightUp[1])
        return false;
    return true;
}