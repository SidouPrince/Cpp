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
    case 3: this->etat = this->TEUPORS_CLOSED;
        break;
    case 4: this->etat = this->EMPTY;
        break;
    case 5: this->etat = this->PLAYER;
        break;
    case 6: this->etat = this->STREUMON;
        break;
    case 7: this->etat = this->TEUPORS_OPEN;
        break;    
    default:
        break;
    }
}
bool Case::isDollar(){
    if( this->etat == DIAMS ) return true;
    return false;
}
bool Case::isTeleport(){
    if( this->etat == GEURCHARS ) return true;
    return false;
}
bool Case::isOpen(){
    if ( this->etat == TEUPORS_OPEN ) return true;
    return false;
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
    case 5: return "J";
        break;
    case 6: return "S";
        break;
    case 7: return "+";
        break;
    default:
        break;
    }
}
