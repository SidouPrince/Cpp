#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include "Case.hpp"
#include "const.hpp"
#include "Joueur.hpp"
#include "Monstre.hpp"
#include <vector>
class Plateau
{
public:
    int hauteur, largeur;
    vector<int> positions;
    vector<int>  emplacementPortes;
    vector<int>  emplacementMonstres;
    vector<Monstre> monstres;
public:
    Plateau(int hauteur, int largeur);//initialiser la matrice
    void affichagePlateau(Case ( *mm)[LARGEUR]);
    void positionsToMonstre();
    void updatePositionM(Case(*mm)[LARGEUR],vector<Monstre>& m, vector<int> p);
    void placerMurs(Case (*mm)[LARGEUR]);
    void init(Case(*mm)[LARGEUR]);
    void placerObstacles(Case(*mm)[LARGEUR], int niveau);
    void placerPortes(Case(*mm)[LARGEUR]);
    void placerGeurchars(Case(*mm)[LARGEUR]);
    void placerDiams(Case(*mm)[LARGEUR]);
    void placerJoueur(Case(*mm)[LARGEUR]);
    void placerStreumon(Case(*mm)[LARGEUR], int niveau);
    int sauvegarderPlateau(Case(*mm)[LARGEUR], string nomFichier);
    void sauvegardePartie(Case(*mm)[LARGEUR], int score, int teleportation,char const *argv[], int indice, int argc);
    /* Une methode de verification dans notre tableau */
    bool verife(int position, vector<int> v);
    /*Pour retrouver la position initiale du joueur sur le plateau*/
    int getX(Case(*mm)[LARGEUR]);
    int getY(Case(*mm)[LARGEUR]);
    /*retrouver les coordonnées des portes*/
    void getXYportes(Case(*mm)[LARGEUR]);
    void getXYMonstres(Case(*mm)[LARGEUR]);
    /*Update la posotion du joueur*/
    static void updatePosition(Case (*mm)[LARGEUR],Joueur j ,int newX, int newY);
    /*Validité d'une position*/
    static bool validePosition(Case (*mm)[LARGEUR], int x, int y, Joueur& joueur){
        if ( mm[x][y].getEtat() == "X" ) return false;
        if ( mm[x][y].getEtat() == "S" ) joueur.setGameOver(1);
        return true;    
    }
    static bool validePositionM(Case (*mm)[LARGEUR], int x, int y){
        if ( mm[x][y].getEtat() == "X" ) return false;
        if ( mm[x][y].getEtat() == "$" ) return false;
        if ( mm[x][y].getEtat() == "*" ) return false;
        if ( mm[x][y].getEtat() == "+" ) return false;
        if ( mm[x][y].getEtat() == "-" ) return false;
        return true;    
    }
    bool isDollar(Case (*mm)[LARGEUR], int x, int y);
    bool isGueurchar(Case (*mm)[LARGEUR], int x, int y);
    //ouvrir Une porte
    void openDoor(Case (*mm)[LARGEUR], int x, int y);
    bool isOpen(Case(*mm)[LARGEUR], int x, int y);
};
#endif