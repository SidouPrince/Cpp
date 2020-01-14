#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include "Case.hpp"
#include "const.hpp"
using namespace std;

class Joueur
{
private:
    int xLoc, yLoc, xMax, yMax, gameOver;
    int score, teleportations;

public:
    Joueur(int x, int y, int score, int teleportations,int gameOver);

    int getX();
    int getGameOver();
    int getY();
    int getScore();
    int getTeleportation();
    void setX(int newX);
    void setGameOver(int un);
    void setY(int newY);
    void setScore(int v);
    void setTeleportation(int v);
    void haut();
    void bas(int hauteur);
    void gauche();
    void droit();

    void diagonalDH();
    void diagonalDB();
    void diagonalGB();
    void diagonalGH();
    
    
    bool seTeleporter(Case ( *matrice)[LARGEUR]);
    void ramasserDiams();
    void sortir();
    Joueur();
    
};
#endif