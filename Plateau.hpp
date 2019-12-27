#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include "Case.hpp"
class Plateau
{
public:
     int hauteur, largeur;

public:
    Plateau(int hauteur, int largeur);//initialiser la matrice
    void affichagePlateau(Case ( *mm)[20]);
    void placerMurs(Case (*mm)[20]);
    void init(Case(*mm)[20]);
};

#endif