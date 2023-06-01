/**
 * @file Scene.hh
 * @author Kacper Ugorny (263504@student.pwr.edu.pl)
 * @brief Plik naglowkowy sceny
 * @version 0.1
 * @date 2022-05-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <memory>
#include <string>
#include <Rover.hh>
#include "RegSample.hh"
#include <unistd.h>
#include "Kolory.hh"
#include "RoverSFR.hh"
#include <cmath>
#include <list>
#include "PowierzchniaMarsa.hh"
#include "lacze_do_gnuplota.hh"

#define FPS 30


/**
 * @brief Klasa Sceny 
 * 
 *  Zawiera wszystkie funkcje potrzebne do kontroli tego co sie dzieje
 *  w oknie gnuplota. Zawiera animowane funkcje ruchu i obrotu.
 */
class Scene
{
private:
    /**
     * @brief Pole z aktywnym lazikiem typu shared_ptr
     */
    std::shared_ptr<Rover> ActiveRover;
    /**
     * @brief Lista z obiektami, nie ma tu aktywnego lazika
     *  lista shared_ptr
     */
    std::list<std::shared_ptr<Object>> Objects;
    /**
     * @brief Lacze do gnuplota
     */
    PzG::LaczeDoGNUPlota Lacze;
public:

    /**
     * @brief Konstruktor bezparametryczny
     */
    Scene(){
        InitGnuplotLink();
        AddRoverSFR("../bryly_wzorcowe/szescian3.dat","Simple_Fetch_Rover",Kolor_JasnoNiebieski,{20,20,10},{0,0,0},0,30 ,1000);
        addRover("../bryly_wzorcowe/szescian3.dat","Perseverance",Kolor_Czerwony,{20,20,10},{60,60,0},0,30,100);
        addRover("../bryly_wzorcowe/szescian3.dat","Curiosity",Kolor_Czerwony,{20,20,10},{-20,70,0},0,30,100);
        addSample("Probka 1",{3,6,2},{30,15,0});
        addSample("Probka 2",{3,6,2},{0,40,0});
        addSample("Probka 3",{3,6,2},{-20,-70,0});
        addSample("Probka 4",{3,6,2},{-60,20,0});
        addSample("Probka 5",{3,6,2},{85,-45,0});
        SelectRover(1);
        Draw();
    }

    /**
     * @brief Metoda inicjujaca lacze do gnuplota
     */
    void InitGnuplotLink();

  

    /**
     * @brief Funckja dodajaca lazika do listy 
     * 
     * @param sNameOfFile_ModelBlock Nazwa pliku z bryla modelowa
     * @param sObjectName Nazwa obiektu
     * @param ColourID Id koloru
     * @param Scale wektor skali
     * @param Position wektor pozycji
     * @param Angle kat orientacji
     * @param Velocity predkosc
     * @param Distance dystans
     */
    void addRover(const char* sNameOfFile_ModelBlock, const char* sObjectName, int ColourID, 
    Vector3D Scale,Vector3D Position,
    double Angle, double Velocity, double Distance);
    
    /**
     * @brief Metoda dodajaca probke do listy obiektow
     * 
     * @param sObjectName Nazwa probki
     * @param Scale wektor skali
     * @param Position wektor pozycji
     */
    void addSample(const char* sObjectName, 
    Vector3D Scale,Vector3D Position);

    /**
     * @brief Metoda dodajaca obiekt do listy rysowania
     * 
     * @param Obj 
     */
    void AddToDrawingList(Object &Obj);

    /**
     * @brief metoda rysujaca w gnuplocie
     * 
     */
    void Draw(){Lacze.Rysuj();}

    /**
     * @brief Metoda wyswietlajaca liste lazikow
     * 
     */
    void DisplayRoversList()const;

    /**
     * @brief Metoda wyswietlajaca Liste probek
     * 
     */
    void DisplaySampleList()const;
    /**
     * @brief Wybierz lazik ktorym sterujesz
     * 
     * @param choice nr lazika
     * @return true - powiodlo sie
     * @return false - nieudalo sie
     */
    bool SelectRover(int choice);

    /**
     * @brief Funkcja przesuwajaca lazik z dana predkoscia o droge s
     * ruch jest animowany
     * 
     * @param s  - droga
     * @param velocity  - szybkosc
     */
    void MoveRover(double s, double velocity);

    /**
     * @brief Funkcja obracajaca lazik z animacja
     * 
     * @param angle - kat o ile ma sie orbrocic 
     */
    void RotateRover(double angle);

    /**
     * @brief Zwroc nazwe aktywnego lazika
     * 
     * @return std::string nazwa
     */
    std::string Rover_name()const{return ActiveRover->ReturnObjectName();}

    /**
     * @brief Zwroc pozycje aktywnego lazika
     * 
     * @return Vector3D wektor polozenia
     */
    Vector3D Rover_pos()const{return ActiveRover->returnPosition();}
    
    /**
     * @brief Zwroc kat orientacji aktywnego lazika
     * 
     * @return double kat
     */
    double Rover_angle()const{return ActiveRover->returnAngle();}


    /**
     * @brief Wykonuje "8" na ekranie
     * 
     */
    void Drive_test();


    /**
     * @brief Sprawdza czy jest kolizja z jakims obiektem sceny
     * 
     * @return CollisionType 
     */
    CollisionType CheckCollisions() const;

    /**
     * @brief Funckja dodajaca lazik SFR do listy obiektow
     * 
     * @param sNameOfFile_ModelBlock nazwa pliku z bryla modelowa
     * @param sObjectName nazwa obiektu
     * @param ColourID id koloru
     * @param Scale wektor skali
     * @param Position wektor pozycji
     * @param Angle kat orientacji
     * @param Velocity predkosc
     * @param Distance dystans
     */
    void AddRoverSFR(const char* sNameOfFile_ModelBlock, const char* sObjectName, int ColourID, 
    Vector3D Scale,Vector3D Position,
    double Angle, double Velocity, double Distance);


    /**
     * @brief Zbiera probke ktora koliduje z lazikiem SFR
     * 
     */
    void CollectSample();


    /**
     * @brief Wyswietla informacje o aktywnym laziku
     * 
     */
    void RoverInfo(){ActiveRover->RoverState();}




};
