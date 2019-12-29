#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include "Case.hpp"
#include "const.hpp"
#include "Joueur.hpp"
#include <vector>
class Plateau
{
public:
    int hauteur, largeur;
    vector<int> positions;

public:
    Plateau(int hauteur, int largeur);//initialiser la matrice
    void affichagePlateau(Case ( *mm)[LARGEUR]);
    void placerMurs(Case (*mm)[LARGEUR]);
    void init(Case(*mm)[LARGEUR]);
    void placerObstacles(Case(*mm)[LARGEUR], int niveau);
    void placerPortes(Case(*mm)[LARGEUR]);
    void placerGeurchars(Case(*mm)[LARGEUR]);
    void placerDiams(Case(*mm)[LARGEUR]);
    void placerJoueur(Case(*mm)[LARGEUR]);
    void placerStreumon(Case(*mm)[LARGEUR], int niveau);
    int sauvegarderPlateau(Case(*mm)[LARGEUR], string nomFichier);
    /* Une methode de verification dans notre tableau */
    bool verife(int position, vector<int> v);
    /*Pour retrouver la position initiale du joueur sur le plateau*/
    int getX(Case(*mm)[LARGEUR]);
    int getY(Case(*mm)[LARGEUR]);
    /*Update la posotion du joueur*/
    static void updatePosition(Case (*mm)[LARGEUR],Joueur j ,int newX, int newY);
    /*Validité d'une position*/
    static bool validePosition(Case (*mm)[LARGEUR], int x, int y){
        if ( mm[x][y].getEtat() == "X" ) return false;
        if ( mm[x][y].getEtat() == "S" ) return false;
        return true;    
    }
    bool isDollar(Case (*mm)[LARGEUR], int x, int y);
    bool isGueurchar(Case (*mm)[LARGEUR], int x, int y);
};

#endif