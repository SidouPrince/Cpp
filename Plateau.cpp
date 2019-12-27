#include <iostream>
#include "Plateau.hpp"
using namespace std;
Plateau::Plateau(int h, int l){
    this->hauteur = h;
    this->largeur = l;
}

void Plateau::placerMurs(Case ( *matrice)[20]){
    int i = 0;
    //cette boucle pour placer le mur d'en haut
    for (int j = 0; j < 20; j++)
    {
        matrice[i][j].setEtat(0);
    }
    //placer le mur d'en bas
    i = this->hauteur-1;
    for (int j = 0; j < 20; j++)
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
        matrice[i][19].setEtat(0);
    }
}
//initialiser la matrice
void Plateau::init(Case (*m)[20]){
    for (int i = 0; i < this->hauteur; i++)
        {
            for (int j = 0; j < this->largeur; j++)
            {
                m[i][j].setEtat(4);
            }
}
}

/*Affichage du plateau*/
    void Plateau::affichagePlateau(Case ( *m)[20]){
        cout << "la hauteur est " << this->hauteur << endl;
        for (int i = 0; i < this->hauteur; i++)
        {
            for (int j = 0; j < this->largeur; j++)
            {
                cout << m[i][j].getEtat();
            }
            cout << endl;
            
        }
        
    }

