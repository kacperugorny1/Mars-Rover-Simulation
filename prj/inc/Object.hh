/**
 * @file Object.hh
 * @author Kacper Ugorny (263504@student.pwr.edu.pl)
 * @brief Plik zawierajacy klase Object
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef OBJECT_HH
#define OBJECT_HH

#include <string>
#include <Vectors.hh>
#include <Matrix3D.hh>
#include <Contour.hh>
#include <memory>

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "../pliki_do_rysowania"

/**
 * @brief typ kolizji
 * 
 */
enum CollisionType{
    CT_NoCollision = 0,
    CT_Collision = 1,
    CT_RunOverSample = 2,
    CT_CanCollect = 3
};

/**
 * @brief Typ obiektu
 * 
 */
enum ObjectType{
  ObjectT = 1,
  RoverT = 2,
  Sample = 3,
  RoverSFRT = 4
};


class Rover;

/**
 * @brief Klasa Object
 * 
 */
class Object {
  protected:
    /**
     * @brief Nazwa pliku z bryla wzorcowa
     */
    std::string   _NameOfFile_ModelBlock;
    /**
     * @brief Nazwa pliku z bryla rysowana
     * 
     */
    std::string   _NameOfFile_DrawBlock;
    /**
     * @brief Nazwa obiektu
     * 
     */
    std::string   _ObjectName;
    /**
     * @brief Id Koloru
     * 
     */
    int           _ColourID;
    /**
     * @brief Wektor skali
     * 
     */
    Vector3D      _Scale;
    /**
     * @brief Wektor polozenia
     * 
     */
    Vector3D      _Position;
    
    Matrix3D      _RotMatrix;

    Contour       _Contour;
  
  public:
  /**
   * @brief Konstruktor bezparam.
   * 
   */
    Object(){_ObjectName="";_NameOfFile_DrawBlock="";_NameOfFile_ModelBlock="";_ColourID=0;}

    virtual ~Object(){}
   
    /**
     * @brief Construct a new Object object
     * 
     * @param sNameOfFile_ModelBlock Nazwa pliku z bryla
     * @param sObjectName Nazwa obiektu
     * @param ColourID id koloru
     * @param scale wektor skali
     * @param Position wektor polozenia
     */
    Object(const char* sNameOfFile_ModelBlock, const char* sObjectName, int ColourID,Vector3D scale, Vector3D Position);
   
  
    /**
     * @brief Zwraca id koloru
     * 
     * @return int 
     */
    int ReturnColourID() const { return _ColourID; }

    Contour ReturnContour() const{return _Contour;}
  
    /**
     * @brief Zwraca nazwe obiektu
     * 
     * @return const std::string& 
     */
    const std::string & ReturnObjectName() const { return _ObjectName; }

    /**
     * @brief Zwraca nazwe pliku z bryla rysowana
     * 
     * @return const std::string& 
     */
    const std::string & ReturnNameOfFile_DrawBlock() const
                 { return _NameOfFile_DrawBlock; }

    /**
     * @brief inicjalizuje strumienie i wywoluje z nimi 
     * funkcje Count_and_save_top(std::istream &StrmIn,std::ostream &StrmOut)
     * 
     * @return true 
     * @return false 
     */
    bool Count_and_save_tops() ;
				     
    /**
     * @brief Oblicza wierzcholki
     * 
     * @return true 
     * @return false 
     */
    bool Count_and_save_tops(std::istream &,std::ostream &) ;


    /**
     * @brief Zwraca typ obiektu
     * 
     * @return ObjectType 
     */
    virtual ObjectType ReturnType()const {return ObjectT;}


    /**
     * @brief Sprawdza kolizje pomiedzy 2 obiektami
     * 
     * @param Obj_ptr 
     * @return CollisionType 
     */
    virtual CollisionType IsCollision(const std::shared_ptr<Rover>& Obj_ptr)const = 0;


};




#endif
