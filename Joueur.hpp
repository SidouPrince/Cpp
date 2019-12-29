#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include "Case.hpp"
using namespace std;

class Joueur
{
private:
    int xLoc, yLoc, xMax, yMax;
    int score, teleportations;

public:
    Joueur(int x, int y, int score, int teleportations);

    int getX();
    int getY();
    int getScore();
    int getTeleportation();
    void setX(int newX);
    void setY(int newY);
    void setScore(int v);
    void setTeleportation(int v);
    void haut();
    void bas(int hauteur);
    void gauche();
    void droit();
    
    void seTeleporter();
    void ramasserDiams();
    void sortir();
    Joueur();
    
};
#endif