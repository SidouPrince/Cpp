#include <iostream>
#include "Plateau.hpp"
#include "Joueur.hpp"
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
Plateau::Plateau(int h, int l){
    this->hauteur = h;
    this->largeur = l;
}

void Plateau::placerMurs(Case ( *matrice)[LARGEUR]){
    int i = 0;
    //cette boucle pour placer le mur d'en haut
    for (int j = 0; j < LARGEUR; j++)
    {
        matrice[i][j].setEtat(0);
    }
    //placer le mur d'en bas
    i = this->hauteur-1;
    for (int j = 0; j < LARGEUR; j++)
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
        matrice[i][(LARGEUR-1)].setEtat(0);
    }
}
//initialiser la matrice
void Plateau::init(Case (*m)[LARGEUR]){
    for (int i = 0; i < this->hauteur; i++)
        {
            for (int j = 0; j < this->largeur; j++)
            {
                m[i][j].setEtat(4);
            }
}
}

/*Affichage du plateau*/
    void Plateau::affichagePlateau(Case ( *m)[LARGEUR]){
        for (int i = 0; i < this->hauteur; i++)
        {
            for (int j = 0; j < this->largeur; j++)
            {
                cout << m[i][j].getEtat();
            }
            cout << endl;
            
        }
        
    }

/* verifier si une position est deja existante */
bool Plateau::verife(int p, vector<int> v){
    for (auto i = v.begin(); i != v.end(); i++)
    {
        if ( *i == p )
        {
            return true;//si ça existe
        }
        
    }
    return false;
    
}

/*Plcaer des obstacles dans la matrices */
void Plateau::placerObstacles(Case(*mm)[LARGEUR], int niveau){
    int borneSup = niveau * 2;
    cout << "niveau : " << borneSup << endl;
    int x = 0, y = 0;//les coordonnees du lobstacle
    srand(time(NULL));
    int indice = 0;
    while (indice < borneSup)
    {
        x = rand()%(this->hauteur - 2)+1;
        y = rand()% LARGEUR;
        //si la position n'existe pas !
        if ( !this->verife((x-y), this->positions) )
        {
           this->positions.push_back((x-y));
           //maintenant on place l'obstacle
           mm[x][y].setEtat(0);
           indice++;

        }
        
    }
}

void Plateau::placerPortes(Case(*mm)[LARGEUR]){

     int x = 0, y = 0;//les coordonnees de la porte
     int p1 = 0, p2 = 0;
     while (p1 == p2)
     {
        p1 = rand()%4;
        p2 = rand()% 4;
     }
     switch (p1)
     {
     case 0://dans le haut de la matrice
        x = 0;
        y = rand()% (LARGEUR-1);
        mm[x][y].setEtat(3);
         
         break;
    case 1://dans le bas de la matrice
        x = hauteur -1;
        y = rand()% LARGEUR;
        mm[x][y].setEtat(3);
        break;
    case 2://sur le coté gauche
        x = rand()%hauteur-1;
        y = 0;
        mm[x][y].setEtat(3);
        break;
    case 3:
        //sur le coté droit
        x = rand()%hauteur-1;
        y = LARGEUR  - 1;
        mm[x][y].setEtat(3);
        break;
     
     default:
         break;
     }

     switch (p2)
     {
     case 0://dans le haut de la matrice
        x = 0;
        y = rand()% LARGEUR-1;
        mm[x][y].setEtat(3);
         
         break;
    case 1://dans le bas de la matrice
        x = hauteur -1;
        y = rand()% LARGEUR;
        mm[x][y].setEtat(3);
        break;
    case 2://sur le coté gauche
        x = rand()%hauteur-1;
        y = 0;
        mm[x][y].setEtat(3);
        break;
    case 3:
        //sur le coté droit
        x = rand()%hauteur-1;
        y = LARGEUR - 1;
        mm[x][y].setEtat(3);
        break;
     
     default:
         break;
     } 
}
void Plateau::placerGeurchars(Case(*mm)[LARGEUR]){
        int x = 0, y = 0;
        x = (rand()%(this->hauteur - 2))+1;
        y = rand()% LARGEUR - 2;
        //si la position n'existe pas !
        if ( !this->verife((x-y), this->positions) )
        {
           this->positions.push_back((x-y));
           //maintenant on place l'obstacle
           mm[x][y].setEtat(2);
        }
}

void Plateau::placerDiams(Case(*mm)[LARGEUR]){
    int x = 0, y = 0, indice =0;

    while (indice < 2)
    {
        x = rand()%(this->hauteur - 2)+1;
        y = rand()% LARGEUR - 2;
        //si la position n'existe pas !
        if ( !this->verife((x-y), this->positions) )
        {
           this->positions.push_back((x-y));
           //maintenant on place l'obstacle
           mm[x][y].setEtat(1);
           indice++;

        }
        
    }
}

void Plateau::placerJoueur(Case(*mm)[LARGEUR]){
    int x = 0, y = 0, indice = 0;
    while (indice < 1)
    {
        x = rand()%(this->hauteur - 2)+1;
        y = rand()% LARGEUR - 2;
        //si la position n'existe pas !
        if ( !this->verife((x-y), this->positions) )
        {
           this->positions.push_back((x-y));
           //maintenant on place l'obstacle
           mm[x][y].setEtat(5);
          indice++;
        }
    }

}

void Plateau::placerStreumon(Case(*mm)[LARGEUR], int niveau){
    int borneSup = niveau + 1;
    int x = 0, y = 0;//les coordonnees du lobstacle
    srand(time(NULL));
    int indice = 0;
    while (indice < borneSup)
    {
        x = rand()%(this->hauteur - 2)+1;
        y = rand()% LARGEUR - 2;
        //si la position n'existe pas !
        if ( !this->verife((x-y), this->positions) )
        {
           this->positions.push_back((x-y));
           //maintenant on place l'obstacle
           mm[x][y].setEtat(6);
           indice++;

        }
        
    }
}
int Plateau::sauvegarderPlateau(Case (*mm)[LARGEUR], string nomFichier){
    ofstream monFichier("Niveaux/"+nomFichier);
    if ( monFichier )
    {
        for (int i = 0; i < hauteur; i++)
        {
            for (int j = 0; j < LARGEUR; j++)
            {
                monFichier << mm[i][j].getEtat();
            }
            monFichier << endl;
            
        }
        
    }else{
        cout << "ERREUR : Impossible d'ouvrir le fichier " << endl;
        return 0;
    }
    
}

/*getX et getY pour retrouver la position du joueur*/
int Plateau::getX(Case(*mm)[LARGEUR]){
    for (int i = 1; i <= hauteur; i++)
        {
            for (int j = 1; j <= LARGEUR; j++)
            {
               if ( mm[i][j].getEtat().compare("J") == 0 )
               {
                   /* ça veut dire que le joueur se trouve dans cette case */
                   return i;
               }
               
            }
            
        }
}

int Plateau::getY(Case(*mm)[LARGEUR]){
    for (int i = 1; i <= hauteur; i++)
        {
            for (int j = 1; j <= LARGEUR; j++)
            {
                if ( mm[i][j].getEtat().compare("J") == 0 )
               {
                   /* ça veut dire que le joueur se trouve dans cette case */
                   return j;
               }
            }
            
            
        }
}

 void Plateau::updatePosition(Case(*mm)[LARGEUR],Joueur j, int oldx, int oldy){
    int newx = j.getX();
    int newy = j.getY();
        //je deplace directement
        mm[oldx][oldy].setEtat(4);
        mm[newx][newy].setEtat(5);
    
}

bool Plateau::isGueurchar(Case (*mm)[LARGEUR], int x, int y){
        if( mm[x][y].isTeleport() ) return true;
        return false;
    }
bool Plateau::isDollar(Case (*mm)[LARGEUR], int x, int y){
        if( mm[x][y].isDollar() ) return true;
        return false;
    }