#include <Vectors.hh>


Vector3D SetAccuracy3dgts(Vector3D x)
{
  Vector3D result;
  result = x;
  for (int i = 0; i<3;++i){
    result[i] = result[i]*1000;
    result[i] = int(result[i]);
    result[i] = double(result[i]);
    result[i] = result[i]/1000;
  }
  return result;
}

bool operator==(Vector3D z,Vector3D wynik){
    z = SetAccuracy3dgts(z);
    wynik = SetAccuracy3dgts(wynik);
    if(z[0]==wynik[0]&&z[1]==wynik[1]&&z[2]==wynik[2])
        return true;
    else
        return false;
}
