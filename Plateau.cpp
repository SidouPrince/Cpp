#include <iostream>
#include "Plateau.hpp"
using namespace std;
Plateau::Plateau(int l, int h){
    this->largeur = l;
    this->hauteur = h;
}

void Plateau::placerMurs(Case **matrice){
    int i = 0;
    //cette boucle pour placer le mur d'en haut
    for (int j = 0; j < this->largeur; j++)
    {
        matrice[i][j].setEtat(0);
    }
    //placer le mur d'en bas
    i = this->hauteur-1;
    for (int j = 0; j < this->largeur; j++)
    {
        matrice[i][j].setEtat(0);
    }

    //placer le mur à gauche
    for (int i = 0; i < this->hauteur; i++)
    {
        matrice[i][0].setEtat(0);
    }
    //placer le mur à droite
    for (int i = 0; i < this->hauteur; i++)
    {
        matrice[i][(this->largeur) - 1].setEtat(0);
    }
}

/*Affichage du plateau*/
    void Plateau::affichagePlateau(Case **m){
        for (int i = 0; i < this->hauteur; i++)
        {
            for (int j = 0; j < this->largeur; j++)
            {
                cout << m[i][j].getEtat();
            }
            cout << endl;
            
        }
        
    }
 
