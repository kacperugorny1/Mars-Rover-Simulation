/**
 * @file vector.hh
 * @author Kacper Ugorny (263504@student.pwr.edu.pl)
 * @brief Plik naglowkowy z szablonem tVector
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once


#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

/**
 * @brief Szablon tVector
 * 
 * @tparam tType - Typ zmiennej
 * @tparam tSize - rozmiar
 */
template <typename tType, int tSize>
class tVector {

private:
    
    /**
     * @brief Tablica wektora;
     */
    tType size[tSize]; 
    
    /**
     * @brief Zmienna statyczna liczaca wektory
     */
    inline static unsigned int vector_counter = 0;
    
    /**
     * @brief Zmienna statyczna liczaca zniszczone wektory
     */
    inline static unsigned int destroyed_vectors = 0;

public:
    
    /**
     * @brief Konstruktor klasy tVector bezparametryczny
     */
    tVector<tType,tSize>() {for (tType &x: size) x=0;++vector_counter;}

    /**
     * @brief Konstruktor parametryczny
     * 
     */
    tVector(tType [tSize]);

    /**
     * @brief Construct a new t Vector object
     * 
     * @param ListaWsp 
     */
    tVector(const std::initializer_list<tType> &ListaWsp);

    /**
     * @brief Konstruktor kopiujacy
     * 
     * @param v kopiowany wektor
     */
    tVector(const tVector & v);

    /**
     * @brief Destruktor
     * 
     */
    ~tVector(){++destroyed_vectors;}

    /**
     * @brief operator przypisania
     * 
     * @param v 
     * @return tVector<tType,tSize>& 
     */
    tVector<tType,tSize> &operator=(const tVector<tType,tSize> &v); 
    
    /**
     * @brief DOdawanie 2 wektorow
     * 
     * @param v - dodawany wektor
     * @return tVector<tType,tSize> Wynik dodawania
     */
    tVector<tType,tSize> operator + (const tVector<tType,tSize> &v) const;

    /**
     * @brief Odejmowanie 2 wektorow
     * 
     * @param v Odejmowany wektor
     * @return tVector<tType,tSize> - Wynik odejmowania 
     */
    tVector<tType,tSize> operator - (const tVector<tType,tSize> &v) const;

    /**
     * @brief Mnozenie wektora przez stala
     * 
     * @param tmp liczba przez ktora mnozony jest wektor
     * @return tVector<tType,tSize> wynik mnozenia
     */
    tVector<tType,tSize> operator * (const double &tmp) const;

    /**
     * @brief Mnozenie skalarne wektorow
     * 
     * @param v Drugi skladnik mnozenia
     * @return tType Wynik mnozenia
     */
    tType operator * (const tVector<tType,tSize> &v) const;

    /**
     * @brief Dzielenie wektora przez liczbe
     * 
     * @param tmp dzielnik
     * @return tVector<tType,tSize> Wynik dzielenia
     */
    tVector<tType,tSize> operator / (const double &tmp) const;

    /**
     * @brief Zwraca wartosc wektora w danym miejscu
     * 
     * @param index - nr miejsca w tabeli wektora
     * @return const tType& - zwracana wartosc
     */
    const tType &operator [] (int index) const;

    /**
     * @brief Zwraca adres do wektora w danym miejscu
     * 
     * @param index nr miejsca w tabeli wektora
     * @return tType& - zwracany adres
     */
    tType &operator [] (int index);
    
    /**
     * @brief Funkcja liczaca wektory
     * 
     */
    static void Count_vectors() __attribute__ ((destructor));

};

template<typename tType, int tSize>
tVector<tType,tSize>::tVector(const tVector<tType,tSize> &v){
    for (int i=0;i<tSize;++i)
        size[i]=v[i];
    vector_counter++;
}

/******************************************************************************
 |  Konstruktor klasy tVector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template <typename tType, int tSize>
tVector<tType,tSize>::tVector(tType tmp[tSize]) {
    for (int i = 0; i < tSize; ++i) {
        size[i] = tmp[i];
    }
    vector_counter++;
}

template <typename tType, int tSize>
tVector<tType,tSize>::tVector(const std::initializer_list<tType> &ListaWsp){
    int Ind = -1;
    for(tType wsp:ListaWsp)
        size[++Ind] = wsp;
    vector_counter++;
}


/**
 * @brief Operator przypisania
 * 
 * @tparam tType 
 * @tparam tSize 
 * @param v - przypisywane wartosci
 * @return tVector<tType,tSize>& 
 */
template <typename tType, int tSize>
tVector<tType,tSize> &tVector<tType, tSize>::operator=(const tVector &v) {
    for (int i = 0; i < tSize; ++i)
        size[i] = v[i];
    return *this;
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template <typename tType, int tSize>
tVector<tType,tSize> tVector<tType,tSize>::operator + (const tVector<tType,tSize> &v) const{
    tVector<tType,tSize> result;
    for (int i = 0; i < tSize; ++i) {
        result[i] = size[i] + v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template <typename tType, int tSize>
tVector<tType,tSize> tVector<tType,tSize>::operator - (const tVector<tType,tSize> &v) const{
    tVector<tType,tSize> result;
    for (int i = 0; i < tSize; ++i) {
        result[i] = size[i] - v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */

template <typename tType, int tSize>
tVector<tType,tSize> tVector<tType,tSize>::operator * (const double &tmp) const{
    tVector<tType,tSize> result;
    for (int i = 0; i < tSize; ++i) {
        result[i] = size[i] * tmp;
    }
    return result;
}

/*
 * Mnozenie skalarne wektorow
 * Argumenty:
 *  this - Pierwszy skladnik
 *  v - drugi skladnik 
 * Zwraca:
 *  wartosc mnozenia skalarnego
 */

template <typename tType, int tSize>
tType tVector<tType,tSize>::operator * (const tVector<tType,tSize> &v) const{
    tType result=size[0] * v[0];
    for (int i = 1; i<tSize; ++i){
        result += size[i] * v[i];
    }
    return result;
}

/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */

template <typename tType, int tSize>
tVector<tType,tSize> tVector<tType,tSize>::operator / (const double &tmp) const{
    tVector<tType,tSize> result;

    for (int i = 0; i < tSize; ++i) {
        result[i] = size[i] / tmp;
    }

    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template <typename tType, int tSize>
const tType &tVector<tType,tSize>::operator [] (int index) const {
    if (index < 0 || index >= tSize) 
        throw std::runtime_error("Error: Wektor jest poza zasiegiem");
    return size[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template <typename tType, int tSize>
tType &tVector<tType,tSize>::operator[](int index) {
    return const_cast<tType &>(const_cast<const tVector<tType,tSize> *>(this)->operator[](index));
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template <typename tType, int tSize>
std::ostream &operator << (std::ostream &out, tVector<tType,tSize> const &tmp) {
    for (int i = 0; i < tSize; ++i) {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template <typename tType, int tSize>
std::istream &operator >> (std::istream &in, tVector<tType,tSize> &tmp) {
    for (int i = 0; i < tSize; ++i) {
        in >> tmp[i];
    }
    return in;
}

/**
 * @brief Obsluga liczenia wektorow
 * 
 * @tparam tType 
 * @tparam tSize 
 */
template <typename tType, int tSize>
void tVector<tType,tSize>::Count_vectors(){
    int actual=vector_counter-destroyed_vectors;
    std::cout<<"Ilosc stworzonych wektorow: "<<vector_counter<<std::endl;
    std::cout<<"Aktualna ilosc wektorow: "<<actual<<std::endl;
}


/*
 *  metoda length() liczy dlugosc wektora
 *  Argumenty:
 *  this
 *  zwraca:
 *  double
 */
/*
template <typename tType,int tSize>
double tVector<tType,tSize>::length(){
    double len = 0;
    for(tType x: size)
        len +=pow(x,2);
    len = sqrt(len);
    return len;
}
*/
/*
 *  metoda length() liczaca dlugosc wektora dla Liczby zespolonej 
 *  argumenty:
 *  this
 *  zwraca:
 *  double
 */
/*
template <>
double tVector<LZespolona,3>::length(){
    double len=0;
    for (LZespolona x: size)
        len += x.Mod_kwadrat();
    len = sqrt(len);
    return len;
}
*/