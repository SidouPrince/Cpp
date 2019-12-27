#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include "Case.hpp"
class Plateau
{
public:
     int hauteur, largeur;
     Case cases[10][10];

public:
    Plateau(int largeur, int hauteur);//initialiser la matrice
    void affichagePlateau(Case *m);
    void placerMurs(Case **m);
};

#endif