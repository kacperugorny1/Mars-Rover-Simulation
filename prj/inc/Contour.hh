#pragma once

#include "Vectors.hh"



class Contour
{
    Vector2D LeftDown;
    Vector2D RightUp;

public:
    /**
     * @brief Construct a new Contour object
     * 
     */
    Contour(){LeftDown[1]=0;LeftDown[0]=0;RightUp[1]=0;RightUp[0]=0;}

    /**
     * @brief Construct a new Contour object
     * 
     */
    Contour(Vector2D LD,Vector2D RU){LeftDown=LD;RightUp=RU;}


    /**
     * @brief Check collision
     * 
     */
    bool IsImposed(Contour x) const;


    /**
     * @brief Zwraca referencje do LeftDown
     * 
     * @return Vector2D& 
     */
    Vector2D &ReturnLDvect(){return LeftDown;}
    
    /**
     * @brief Zwraca referencje do RightUp
     * 
     * @return Vector2D& 
     */
    Vector2D &ReturnRUvect(){return RightUp;}
};

