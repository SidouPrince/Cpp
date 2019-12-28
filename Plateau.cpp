#include <iostream>
#include "Plateau.hpp"
#include <ctime>
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
void Plateau::placerObstacles(Case(*mm)[20], int niveau){
    int borneSup = niveau * 2;
    cout << "niveau : " << borneSup << endl;
    int x = 0, y = 0;//les coordonnees du lobstacle
    srand(time(NULL));
    int indice = 0;
    while (indice < borneSup)
    {
        x = rand()%(this->hauteur - 2)+1;
        y = rand()% 18;
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

void Plateau::placerPortes(Case(*mm)[20]){

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
        y = rand()% 19;
        mm[x][y].setEtat(3);
         
         break;
    case 1://dans le bas de la matrice
        x = hauteur -1;
        y = rand()% 20;
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
        y = 19;
        mm[x][y].setEtat(3);
        break;
     
     default:
         break;
     }

     switch (p2)
     {
     case 0://dans le haut de la matrice
        x = 0;
        y = rand()% 19;
        mm[x][y].setEtat(3);
         
         break;
    case 1://dans le bas de la matrice
        x = hauteur -1;
        y = rand()% 20;
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
        y = 19;
        mm[x][y].setEtat(3);
        break;
     
     default:
         break;
     } 
}
void Plateau::placerGeurchars(Case(*mm)[20]){
        int x = 0, y = 0;
        x = (rand()%(this->hauteur - 2))+1;
        y = rand()% 18;
        //si la position n'existe pas !
        if ( !this->verife((x-y), this->positions) )
        {
           this->positions.push_back((x-y));
           //maintenant on place l'obstacle
           mm[x][y].setEtat(2);
        }
}

void Plateau::placerDiams(Case(*mm)[20]){
    int x = 0, y = 0, indice =0;

    while (indice < 2)
    {
        x = rand()%(this->hauteur - 2)+1;
        y = rand()% 18;
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

void Plateau::placerJoueur(Case(*mm)[20]){
    int x = 0, y = 0, indice = 0;
    while (indice < 1)
    {
        x = rand()%(this->hauteur - 2)+1;
        y = rand()% 18;
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

void Plateau::placerStreumon(Case(*mm)[20], int niveau){
    int borneSup = niveau + 1;
    int x = 0, y = 0;//les coordonnees du lobstacle
    srand(time(NULL));
    int indice = 0;
    while (indice < borneSup)
    {
        x = rand()%(this->hauteur - 2)+1;
        y = rand()% 18;
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