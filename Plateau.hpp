#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include "Case.hpp"
#include <vector>
class Plateau
{
public:
    int hauteur, largeur;
    vector<int> positions;

public:
    Plateau(int hauteur, int largeur);//initialiser la matrice
    void affichagePlateau(Case ( *mm)[20]);
    void placerMurs(Case (*mm)[20]);
    void init(Case(*mm)[20]);
    void placerObstacles(Case(*mm)[20], int niveau);
    void placerPortes(Case(*mm)[20]);
    void placerGeurchars(Case(*mm)[20]);
    void placerDiams(Case(*mm)[20]);
    void placerJoueur(Case(*mm)[20]);
    void placerStreumon(Case(*mm)[20], int niveau);
    /* Une methode de verification dans notre tableau */
    bool verife(int position, vector<int> v);
};

#endif