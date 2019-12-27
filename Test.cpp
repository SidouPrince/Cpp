#include <iostream>
#include "Case.hpp"
#include "Plateau.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    //creation du plateau -----> maintenant il faut le remplir
    int hauteur, largeur;
    cout << "veuillez introduire une hauteur ..";
    cin >> hauteur;
    
    
    Case m[hauteur][20];
    
    Plateau plateau(hauteur, 20);
    plateau.init(m);
    plateau.placerMurs(m);
    plateau.affichagePlateau(m);



    return 0;
}
