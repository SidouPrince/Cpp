#ifndef FICHIER_H
#define FICHIER_H
#include <iostream>
#include "const.hpp"
#include "Case.hpp"
#include "Plateau.hpp"
#include "Joueur.hpp"
#include <fstream>

void lireFichier(string nomFichier){
    ifstream fichier("Niveaux/"+nomFichier);

        string ligne;
        while ( getline(fichier, ligne))
        {
            cout << ligne << endl;
        }
}
//hauteur du fichier cad la matrice (nb de lignes)
int getHauteur(string nomFichier){
    ifstream fichier("Niveaux/"+nomFichier);

        string ligne;
        int nbLine = 0;
        while ( getline(fichier, ligne))
        {
            nbLine++;
        }
    return nbLine;
}

//initialiser la matrice
void uploadLevel(Case (*m)[LARGEUR], string nomFichier){
    int nbLignes = getHauteur(nomFichier);
    ifstream fichier("Niveaux/"+nomFichier);
    string s; int i = 0;
    while ( getline(fichier, s) )
    {
        for (int j = 0; j < LARGEUR; j++)
            {
                switch (s[j])
                {
                case 'X':
                    m[i][j].setEtat(0);
                    break;
                case '$':
                    m[i][j].setEtat(1);
                    break;
                case '*':
                    m[i][j].setEtat(2);
                    break;
                case '-':
                    m[i][j].setEtat(3);
                    break;
                case ' ':
                    m[i][j].setEtat(4);
                    break;
                case 'J':
                    m[i][j].setEtat(5);
                    break;
                case 'S':
                    m[i][j].setEtat(6);
                    break;
                default:
                    break;
                }    
            }
             i++;
    }  
}

#endif