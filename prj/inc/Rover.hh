/**
 * @file Rover.hh
 * @author Kacper Ugorny (263504@student.pwr.edu.pl)
 * @brief Plik naglowkowy lazika
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "Object.hh"


/**
 * @brief Klasa Rover - Lazik
 * Dziedziczy od Object
 * 
 */
class Rover : public Object{
protected:
    /**
     * @brief Okresla predkosc maksymlna lazika
     * 
     */
    double _Velocity;
    /**
     * @brief Okresla droge do przejechania
     * narazie nieuzytek
     */
    double _Distance;
    /**
     * @brief Okresla kat rotacji
     * 
     */
    double _RotationAngle;
public:


    virtual ~Rover(){}

    /**
     * @brief Konstruktor bezparametryczny
     * 
     */
    Rover();
    /**
     * @brief Construct a new Rover object
     * 
     * @param sNameOfFile_ModelBlock Nazwa pliku z bryla modelowa
     * @param sObjectName Nazwa objektu
     * @param ColourID Id koloru
     * @param Scale wektor skali
     * @param Postition Wektor pozycji
     * @param angle kat 
     * @param Velocity predkosc
     * @param Distance dystans
     */
    Rover(const char* sNameOfFile_ModelBlock, const char* sObjectName, int ColourID, 
    Vector3D Scale,Vector3D Postition,
    double angle, double Velocity, double Distance
    );
    /**
     * @brief Przesuwa lazik bez animacji o 
     * droge Distance
     * 
     * @param Distance - Droga 
     */
    virtual void MoveRover(double Distance);
    /**
     * @brief Obroc lazik bez animacji o kat
     * Angle
     * 
     * @param Angle - Kat  
     */
    virtual void RotateRover(double Angle);
    /**
     * @brief Zwraca predkosc
     * 
     * @return double - predkosc
     */
    double returnVelocity()const{return _Velocity;}
    /**
     * @brief Zwraca pozycje
     * 
     * @return Vector3D - wektor polozenia(bardziej punkt)
     */
    Vector3D returnPosition()const{return _Position;}
    /**
     * @brief Zwraca kat rotacji
     * 
     * @return double - kat rotacji
     */
    double returnAngle()const{return _RotationAngle;}

    /**
     * @brief Zwraca typ obiektu
     * 
     * @return ObjectType 
     */
    virtual  ObjectType ReturnType()const override{return RoverT;}


    /**
     * @brief Sprawdza kolizje pomiedzy 2 obiektami
     * 
     * @param Obj_ptr 
     * @return CollisionType 
     */
    virtual CollisionType IsCollision(const std::shared_ptr<Rover>& Obj_ptr)const override;   


    /**
     * @brief zwraca informacje o laziku
     * 
     */
    virtual void RoverState()const;


};

