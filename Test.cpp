#include <iostream>
#include "Case.hpp"
#include "Plateau.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    static int niveau = 1;
    int reponse = 0;
    //creation du plateau -----> maintenant il faut le remplir
    int hauteur, largeur;
    bool sortirBoucle = true;
    while(sortirBoucle){
        cout << "veuillez introduire une hauteur ..";
        cin >> hauteur;
        Case m[hauteur][20];
        Plateau plateau(hauteur, 20);
        plateau.init(m);//initialiser la matrice
        plateau.placerMurs(m);
        //plateau.affichagePlateau(m);
        plateau.placerObstacles(m, niveau);
        plateau.placerPortes(m);
        plateau.placerGeurchars(m);
        plateau.placerDiams(m);
        plateau.placerJoueur(m);
        plateau.placerStreumon(m, niveau);
        plateau.affichagePlateau(m); 
        
        //continuer de faire des plateaux ou pas 
        cout << "Créer un nouveau plateau ? 1/0" << endl;
        cin >> reponse;
        if ( reponse == 0 )
        {
            sortirBoucle = false;
        }else{
            niveau = niveau +1;
        }
        
    }
    



    return 0;
}
