#include <iostream>
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "const.hpp"
using namespace std;
Joueur::Joueur(int x, int y, int s, int t){
    this->xLoc = x;
    this->yLoc = y;
    this->score = s;
    this->teleportations = t;
}

void Joueur::haut(){
    //avant modification
    int currentX = this->xLoc;
           setX(currentX - 1);
       
}
void Joueur::bas(int hauteur){
     //avant modification
    int currentX = this->xLoc;
        setX(currentX + 1);
    }
void Joueur::droit(){
     //avant modification
    int currentY = this->yLoc;
        setY(currentY + 1);
    }
void Joueur::gauche(){
     //avant modification
    int currentY = this->yLoc;
        setY(currentY - 1);
    }


int Joueur::getX(){
    return this->xLoc;
}
int Joueur::getY(){
    return this->yLoc;
}

int Joueur::getScore(){
    return this->score;
}
int Joueur::getTeleportation(){
    return this->teleportations;
}

void Joueur::setX(int x){
    this->xLoc = x;
}
void Joueur::setY(int y){
    this->yLoc = y;
}

void Joueur::setScore(int v){
    this->score = v;
}
void Joueur::setTeleportation(int t){
    this->teleportations = t;
}