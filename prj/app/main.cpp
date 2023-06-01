/**
 * @file main.cpp
 * @author Kacper Ugorny (263504@student.pwr.edu.pl)
 * @brief Plik main
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "Object.hh"
#include "Vectors.hh"
#include "Rover.hh"
#include "Scene.hh"
#include "Kolory.hh"


void DisplayMenu(bool &x){
  if(!x)
    return;
  std::cout<<std::endl<<"   Menu"<<std::endl;
  std::cout<<"   j - jazda na wprost"<<std::endl;
  std::cout<<"   o - zmien orientacje"<<std::endl;
  std::cout<<"   w - wybor lazika"<<std::endl;
  std::cout<<"   l - lista probek"<<std::endl;
  std::cout<<"   t - jazda testowa"<<std::endl;
  std::cout<<"   p - podejmij probka (Tylko dla lazika SFR)"<<std::endl;
  std::cout<<"   m - wyswietl menu"<<std::endl<<std::endl;
  std::cout<<"   k - koniec dzialania progamu"<<std::endl;
  x = false;
}


int main()
{
  try{
  char choice;
  double value;
  double dist;
  bool displaymenu = true;
  Scene Scena;
  



  system("clear");
  while (choice != 'k')
  {  
    Scena.RoverInfo();
    tVector<double,3>::Count_vectors();
    DisplayMenu(displaymenu);
    std::cout<<"Twoj wybor, m - menu> ";
    std::cin>>choice;
    while (std::cin.fail()){
      std::cin.clear();
      std::cin.ignore(100000,'\n');
      std::cout<<"Sproboj ponownie: ";
      std::cin>>choice;
    }
    switch (choice){
    case 'j':
      std::cout<<"Podaj odleglosc, na ktora ma sie przemiescic lazik (w jednostkach sceny)\n"<<"Odleglosc> ";
      std::cin>>dist;
      while (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cout<<"Sproboj ponownie: ";
        std::cin>>dist;
        system("clear");
      }
      std::cout<<"Podaj predkosc,z ktora ma sie przemieszczac lazik(jedn.sceny/s) max predkosc = 30\nPredkosc>  ";
      std::cin>>value;
      while (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cout<<"Sproboj ponownie: ";
        std::cin>>value;
      }
      system("clear");
      Scena.MoveRover(dist,value);
      break;
    case 'o':
      std::cout<<"Podaj kat obrotu w stopniach\nKat> ";
      std::cin>>value;
      while (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(100000,'\n');
        std::cout<<"Sproboj ponownie";
        std::cin>>value;
      }
      Scena.RotateRover(value);
      system("clear");
      break;
    case 'w':
      Scena.DisplayRoversList();
      std::cout<<"Nr Lazika> ";
      std::cin>>value;
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout<<"Sproboj ponownie: ";
        std::cin>>value;
      }
      while(!Scena.SelectRover(value)){
        Scena.DisplayRoversList();
        std::cin>>value;    
      }
      system("clear");
      break;
    case 'l':
      system("clear");
      Scena.DisplaySampleList();
      std::cout<<std::endl;
      break;
    case 'p':
      system("clear");
      Scena.CollectSample();
      break;
    case 't':
      Scena.Drive_test();
      system("clear");
      break;
    case 'm':
      system("clear");
      displaymenu = true;
      break;
    case 'k':
      std::cout<<"Koniec programu"<<std::endl;
      break;
    default:
      system("clear");
      std::cout<<"Not an option";
      break;
    }
  }




  return 0;
  }
  catch(std::runtime_error& e){
    std::cerr<<e.what()<<std::endl;
    return 1;
  }
}
