/**
 * @file matrix.hh
 * @author Kacper Ugorny (263504@student.pwr.edu.pl)
 * @brief Plik z szablonem tMatrix
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "vector.hh"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>

/**
 * @brief Szablon tMatrix
 * 
 * @tparam tType Typ zmiennej
 * @tparam tSize Wymiar macierzy
 */
template <typename tType,int tSize>
class tMatrix {

protected:

    /**
     * @brief Wartosci pol macierzy
     */
    tVector<tType,tSize> value[tSize];  // Wartosci macierzy
    

public:

    /**
     * @brief konstruktor
     * 
     * @param tab - tabela z danymi
     */
    tMatrix(tType tab[tSize][tSize]);            // Konstruktor klasy

    /**
     * @brief konstruktor bez parametryczny - wypelnia macierz zerami
     * 
     */
    tMatrix();                               // Konstruktor klasy


    /**
     * @brief Przeciazenie operatora * dla mnozenia Matrix*vector
     * 
     * @param tmp - wektor - skladnik mnozenia
     * @return tVector<tType,tSize> - wynik 
     */
    tVector<tType,tSize> operator * (tVector<tType,tSize> tmp) const;           // Operator mnożenia przez wektor

    /**
     * @brief Przeciazenie operatora + dla dodawania 2 macierzy
     * 
     * @param tmp - macierz dodawana
     * @return tMatrix<tType,tSize> - wynik
     */
    tMatrix<tType,tSize> operator + (tMatrix<tType,tSize> tmp) const;


    /**
     * @brief Przeciazenie operatora() - dostep do adresu danej
     * 
     * @param row 
     * @param column 
     * @return tType& - adres danej
     */
    tType  &operator () (unsigned int row, unsigned int column);
    
    /**
     * @brief Przeciazenie operatore () - zwraca wartosc
     * 
     * @param row 
     * @param column 
     * @return const tType& 
     */
    const tType &operator () (unsigned int row, unsigned int column) const;
    /**
     * @brief Zamiana kolumn
     * 
     * @param column1 nr kolumny
     * @param column2 nr kolumny
     */
    void swap_column(unsigned int column1,unsigned int column2);
    
    /**
     * @brief wstawianie wiersza
     * 
     * @param row - gdzie wstawiamy 
     * @param insert - wektor ktory wstawiamy
     */
    void insert_row(unsigned int row,tVector<tType,tSize> insert);
    
    /**
     * @brief liczy wyznacznik
     * 
     * @return tType wyznacznik
     */
    tType determinant() const;

    /**
     * @brief Transponowanie macierzy
     * 
     */
    void transpose();

    /**
     * @brief liczy norme forebniusa
     * 
     * @return tType - wartosc normy
     */
    tType FrobeniusNorm();

    
    
};


/******************************************************************************
 |  Konstruktor klasy tMatrix<tType,tSize>.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template <typename tType, int tSize>
tMatrix<tType,tSize>::tMatrix() {
    for (int i = 0; i < tSize; ++i) {
        for (int j = 0; j < tSize; ++j) {
            value[i][j] = 0;
        }
    }
}

/******************************************************************************
 |  Konstruktor parametryczny klasy tMatrix<tType,tSize>.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template <typename tType, int tSize>
tMatrix<tType,tSize>::tMatrix(tType tmp[tSize][tSize]) {
    for (int i = 0; i < tSize; ++i) {
        for (int j = 0; j < tSize; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}

/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template <typename tType, int tSize>
tVector<tType,tSize> tMatrix<tType,tSize>::operator * (tVector<tType,tSize> tmp) const{
    tVector<tType,tSize> result;
    for (int i = 0; i < tSize; ++i) {
        for (int j = 0; j < tSize; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
template <typename tType, int tSize>
tMatrix<tType,tSize> tMatrix<tType,tSize>::operator + (tMatrix<tType,tSize> tmp) const{
    tMatrix<tType,tSize> result;
    for (int i = 0; i < tSize; ++i) {
        for (int j = 0; j < tSize; ++j) {
            result(i, j) = value[i][j] + tmp(i, j);
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template <typename tType, int tSize>
tType &tMatrix<tType,tSize>::operator()(unsigned int row, unsigned int column) {

    if (row >= tSize)
        throw std::runtime_error("Error: Macierz jest poza zasiegiem");

    if (column >= tSize) {
        throw std::runtime_error("Error: Macierz jest poza zasiegiem");
}

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template <typename tType, int tSize>
const tType &tMatrix<tType,tSize>::operator () (unsigned int row, unsigned int column) const {

    if (row >= tSize) 
        throw std::runtime_error("Error: Macierz jest poza zasiegiem");

    if (column >= tSize) 
        throw std::runtime_error("Error: Macierz jest poza zasiegiem");

    return value[row][column];
}

/*
 * Funkcja swap_column zamienia kolumny miejscami
 * Argumenty:
 *      unsigned int a - numer pierwszej kolumny
 *      unsigned int b - numer drugiej kolumny
 * Zwraca 
 */
template <typename tType, int tSize>
void tMatrix<tType,tSize>::swap_column(unsigned int a,unsigned int b)
{
    tVector<tType,tSize> help;
    if(a>=tSize||b>=tSize)
        throw std::runtime_error("Error: Macierz jest poza zasiegiem");
    this->transpose();
    help = this->value[a];
    this->value[a] = this->value[b];
    this->value[b] = help;
    this->transpose();
}

/*
 * Funkcja wstawiajaca podmieniajaca wiersz
 * Dane wejsciowe:
 *      unsigned int row - nr wiersza w ktory jest wstawiany inny wektor
 *      tVector<tType,tSize> insert - wektor ktory jest wstawiany
 * Zwraca
 *      void
 * 
 *
 */
template <typename tType, int tSize>
void tMatrix<tType,tSize>::insert_row(unsigned int row,tVector<tType,tSize> insert){
    value[row]=insert;
}


/*
 * metoda determinant - liczy wyznacznik macierzy
 * Argumenty:
 *      this - klasa tMatrix<tType,tSize>
 * Zwraca
 *      tType result - wynik
 * 
 */
template <typename tType, int tSize>
tType tMatrix<tType,tSize>::determinant() const{
    tMatrix<tType,tSize> help = *this;
    tType result,dzielnik;
    bool success;
    int parzystosc = 1;
    for(int i = 0; i<tSize;++i){
        for(int j = i + 1;j<tSize;++j){
            if(help(i,i)==0){
            success=false;
            for(int z = i+1;z<tSize;++z){
                if(!(help(i,z)==0)){
                    help.swap_column(i,z);
                    success=true;
                    parzystosc=-parzystosc;
                    z=tSize;
                    }
                }
                if(success==false){
                    result = 0;
                    return result;
                }
            }
            dzielnik = help(i,j)/help(i,i);
            for(int k = i;k<tSize;++k)
                help(k,j) -= dzielnik*help(k,i);
        }
        if(i==0)
            result = help(i,i);
        else
        result*=help(i,i);
    }
    result*=parzystosc;
    return result;
}


/*
 * Metoda transponse - transponuj macierz
 * Argumenty:
 *  wejscie:
 *      this - wskaznik modyfikowany
 * 
 */
template <typename tType, int tSize>
void tMatrix<tType,tSize>::transpose(){
    tMatrix<tType,tSize> help = *this;
    for(int i=0;i<tSize;++i){
        for(int j=0;j<tSize;++j){
            (*this)(i,j)=help(j,i);
        }
    }
}


/*
 *  Funkcja obliczajaca norme forebniusa
 *  Argumenty:
 *      this
 *  Zwraca:
 *      tType result - wartosc normy forebniusa
 */
template <typename tType, int tSize>
tType tMatrix<tType,tSize>::FrobeniusNorm(){
    tType result=0;
    for(int i=0;i<tSize;++i)
        for(int j=0;j<tSize;++j)
            result += pow((*this)(i,j),2);
    return sqrt(result);
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
template <typename tType, int tSize>
std::istream &operator>>(std::istream &in, tMatrix<tType,tSize> &mat) {
    for(int i = 0; i < tSize; ++i)
        for(int j = 0; j < tSize; ++j)
            in>>mat(i,j);
    mat.transpose();
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template <typename tType, int tSize>
std::ostream &operator<<(std::ostream &out, const tMatrix<tType,tSize> &mat) {
    for (int i = 0; i < tSize; ++i) {
        for (int j = 0; j < tSize; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}
