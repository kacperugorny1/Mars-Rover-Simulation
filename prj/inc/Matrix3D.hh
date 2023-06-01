/**
 * @file Matrix3D.hh
 * @author Kacper Ugorny (263504@student.pwr.edu.pl)
 * @brief Instancja macierzy Matrix3D
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <matrix.hh>


/**
 * @brief Macierz3D dziedziczy z tMatrix
 * 
 */
class Matrix3D: public tMatrix<double,3>{
    public:
    /**
     * @brief dziedziczenie konstruktorow
     * 
     */
    using tMatrix::tMatrix;


    /**
    * @brief wypelnij macierz obrotu Z
    * 
    * @param theta - Kat
    */
    void FillRotationZ(double theta);
    /**
    * @brief wypelnij macierz obrotu Y
    * 
    * @param theta - Kat
    */
    void FillRotationY(double theta);
    /**
    * @brief wypelnij macierz obrotu X
    * 
    * @param theta - Kat
    */
    void FillRotationX(double theta);
};