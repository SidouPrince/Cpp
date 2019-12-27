#include <iostream>
#include "Case.hpp"
using namespace std;


Case::Case(int e){
    this->etat = e;
}
//par defaut
Case::Case(){}  



void Case::setEtat(int etat){
    switch (etat)
    {
    case 0: this->etat = this->REUMUS;
        break;
    case 1: this->etat = this->DIAMS;
        break;
    case 2: this->etat = this->GEURCHARS;
        break;
    case 3: this->etat = this->TEUPORS;
        break;
    case 4: this->etat = this->EMPTY;
        break;
    
    default:
        break;
    }
}

string Case::getEtat(){
    switch (this->etat)
    {
    case 0 : return "X"; 
        break;
    case 1 : return "$"; 
        break;
    case 2 : return "*"; 
        break;
    case 3 : return "-"; 
        break;
    case 4 : return " "; 
        break;
    default:
        break;
    }
}
