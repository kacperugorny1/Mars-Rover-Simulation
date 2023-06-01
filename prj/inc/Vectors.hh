/**
 * @file Vectors.hh
 * @author Kacper Ugorny (263504@student.pwr.edu.pl)
 * @brief Definiuje instancje Vektor3D i Vector2D
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <vector.hh>


/**
 * @brief Vector2D
 * 
 */
typedef tVector<double,2> Vector2D;



/**
 * @brief Vector3D
 * 
 */
typedef tVector<double,3> Vector3D;

/**
 * @brief Dokladnosc do 3 liczb po przecinku
 * 
 * @param x 
 * @return Vector3D 
 */
Vector3D SetAccuracy3dgts(Vector3D x);

/**
 * @brief operator porownania
 * 
 * @param z 1 wektor
 * @param wynik 2 wektor
 * @return true rowne
 * @return false nierowne
 */
bool operator==(Vector3D z,Vector3D wynik);