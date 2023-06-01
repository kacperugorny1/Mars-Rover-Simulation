#pragma once

#include "Object.hh"
#include "Vectors.hh"
#include "Rover.hh"

/**
 * @brief Klasa probka regolitu
 * 
 */
class RegSample: public Object{
    public:
    RegSample(const char* sObjectName, Vector3D Scale,Vector3D Position);

    virtual ~RegSample(){}

    /**
     * @brief Zwraca czy kolizja
     * 
     * @param x 
     * @return CollisionType 
     */
    virtual CollisionType IsCollision(const std::shared_ptr<Rover>& x)const override;
    
    /**
     * @brief Zwraca nazwe typu
     * 
     * @return ObjectType 
     */
    virtual ObjectType ReturnType()const override{return Sample;}


    /**
     * @brief Zwaca referencje do pozycji
     * 
     * @return Vector3D& 
     */
    Vector3D & ReturnPosition(){return _Position;}

    Matrix3D & ReturnRotMatrix(){return _RotMatrix;}
};