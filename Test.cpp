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
    cout << "Veuillez introduire une largeur ..";
    cin >> largeur;
    Case m[hauteur][largeur];
    
    Plateau plateau(hauteur, largeur);
    plateau.placerMurs((Case **)&m);
    plateau.affichagePlateau(&m);



    return 0;
}
