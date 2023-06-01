#pragma once
#include "Rover.hh"
#include "RegSample.hh"
#include <list>



/**
 * @brief Klasa RoverSFR
 * 
 */
class RoverSFR : public Rover{
    private:
    /**
     * @brief Lista zebranych probek
     * 
     */
    std::list<std::shared_ptr<RegSample>> SampleList;
    public:

    /**
     * @brief Uzywa konstruktorow zwyklego lazika
     * 
     */
    using Rover::Rover;


    /**
     * @brief Wyswietla liste zebranych probek
     * 
     */
    void DisplaySampleList()const;

    /**
     * @brief Funkcja przesuwajaca lazik i zebrane probki o distance
     * 
     * @param Distance 
     */
    virtual void MoveRover(double Distance)override;

    /**
     * @brief Funkcja obracajaca lazik i zebrane probki o angle
     * 
     * @param Distance 
     */
    virtual void RotateRover(double Angle)override;

    /**
     * @brief Sprawdza czy koliduje z lazikiem
     * 
     * @param Obj_ptr 
     * @return CollisionType 
     */
    virtual CollisionType IsCollision(const std::shared_ptr<Rover>& Obj_ptr) const override;


    /**
     * @brief Zwraca typ obiektu
     * 
     * @return ObjectType 
     */
    virtual ObjectType ReturnType()const override{return ObjectType::RoverSFRT;}

    /**
     * @brief Usuwa z listy from element what i dodaje go do listy probek
     * 
     * @param from 
     * @param what 
     */
    void AddSampleToList(std::list<std::shared_ptr<Object>>& from, const std::list<std::shared_ptr<Object>>::const_iterator what);

    /**
     * @brief Wyswietla informacje o laziku
     * 
     */
    virtual void RoverState()const override;


};