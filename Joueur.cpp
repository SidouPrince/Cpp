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
        this->setY(currentY + 1);
    }
void Joueur::gauche(){
     //avant modification
    int currentY = this->yLoc;
        this->setY(currentY - 1);
    }


     //  diagonal haut droite 
    void Joueur::diagonalDH(){
     //avant modification
     int currentX = this->xLoc;    
    int currentY = this->yLoc;
        setX(currentX -1);
        setY(currentY + 1);
    }

    //  diagonal  Bas droite 
    void Joueur::diagonalDB(){
     //avant modification
     int currentX = this->xLoc;    
    int currentY = this->yLoc;
        setX(currentX +1);
        setY(currentY + 1);
    }


//  diagonal Bas Gauche 
    void Joueur::diagonalGB(){
     //avant modification
     int currentX = this->xLoc;    
    int currentY = this->yLoc;
        setX(currentX +1);
        setY(currentY - 1);
    }
    void Joueur::diagonalGH(){
     //avant modification
     int currentX = this->xLoc;    
    int currentY = this->yLoc;
        setX(currentX -1);
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
bool Joueur::seTeleporter(Case (*matrice)[LARGEUR]){
    int x = rand()%(18)+1;
    int y = rand()% LARGEUR;

    if (matrice[x][y].getEtat() == "X" || matrice[x][y].getEtat() =="S") return false;//position non valide
    //recuperer les coord actuelles
    int actuelX = this->getX();
    int actuelY = this->getY();
    matrice[x][y].setEtat(5);
    matrice[actuelX][actuelY].setEtat(4);
    this->setX(x);
    this->setY(y);
    return true;
}