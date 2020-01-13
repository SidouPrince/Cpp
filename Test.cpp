#include <iostream>
#include "Case.hpp"
#include "Plateau.hpp"
#include "Joueur.hpp"
#include "Fichier.hpp"
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    /*Touches de jeu
    'h' --> se deplacer en haut
    'b' --> se deplacer en bas
    'g' --> à gauche
    'd' --> droite
    'q' --> quit
    */
    int niveau = 1;
    int reponse = 0, choix = 0;
    string nomF = "";
    char touche ;

    cout << "1- Jouer ?" << endl;
    cout << "2- Créer Plateaux " << endl;
    cin >> choix;
    /* Debut du jeu  */
    if ( choix == 1 ){
   if ( argc > 1 )
   {
       //il y a aumoins un nom de fichier
       int niveau = 1;
       while ( niveau <= argc )
       {
        Case p[getHauteur(argv[niveau])][LARGEUR];
        uploadLevel(p, argv[niveau]);//charger le plateau du fichier sur la matrice
        Plateau pl(getHauteur(argv[niveau]), LARGEUR);
    
        int xLoc = pl.getX(p);
        int yLoc = pl.getY(p);

        //recuperation des portes
        pl.getXYportes(p);

        //creation du joueur
        Joueur joueur(xLoc, yLoc, 0, 0);
        //la boucle d'interaction
        while ( (touche = getchar()) != 'q' )
        {
            
            cout << "Score == " << joueur.getScore() << endl;
            cout << "Teleportations == " << joueur.getTeleportation() << endl;
            int currentX = pl.getX(p);
            int currentY = pl.getY(p);
            if ( touche == 'h' )
            {
                if ( pl.validePosition(p, currentX - 1, currentY) ){
                    if (pl.isDollar(p, currentX -1, currentY)) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX -1, currentY)) joueur.setTeleportation((joueur.getTeleportation())+1);
                     joueur.haut();
                }
            }
            if ( touche == 'b' )
            {
               
                if ( pl.validePosition(p, currentX + 1, currentY) ){ 
                    if (pl.isDollar(p, currentX +1, currentY)) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX +1, currentY)) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.bas(getHauteur(argv[niveau]));
                }
            }
            if ( touche == 'd' )
            {
                
                if ( pl.validePosition(p, currentX, currentY + 1) ) {
                    if (pl.isDollar(p, currentX, currentY + 1)) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX, currentY + 1)) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.droit();
                }
                
                
            }
            if ( touche == 'g' )
            {
                if ( pl.validePosition(p, currentX, currentY -1) ) {
                    cout << p[currentX][currentY -1].getEtat() << endl;
                    if (pl.isDollar(p, currentX, currentY -1)) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX, currentY -1)) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.gauche();
                    
                }
                
            }
            //on test si le joueur à franchi la porte
            if ( pl.isOpen(p, joueur.getX(), joueur.getY()) ){
                break;   
            } 


             if ( touche == 'r' )
            {
                if ( pl.validePosition(p, currentX -1, currentY ) ) {
                    if (pl.isDollar(p, currentX -1, currentY )) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX -1, currentY )) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.diagonalGH();
                    
                }
             }

              if ( touche == 'u' )
            {
                if ( pl.validePosition(p, currentX -1, currentY ) ) {
                    if (pl.isDollar(p, currentX -1, currentY )) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX -1, currentY )) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.diagonalDH();
                    
                }
                
            }

            if ( touche == 'c' )
            {
                if ( pl.validePosition(p, currentX +1, currentY) ) {
                    if (pl.isDollar(p, currentX +1, currentY )) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX +1, currentY )) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.diagonalGB();
                    
                }
            
            }

            if ( touche == 'n' )
            {
                if ( pl.validePosition(p, currentX +1, currentY ) ) {
                    if (pl.isDollar(p, currentX +1, currentY )) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX +1, currentY )) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.diagonalDB();
                    
                }
                
            }

            if ( touche == 't' )
            {
                if ( joueur.getTeleportation() > 0 )
                {
                    if ( ! joueur.seTeleporter(p) ){
                     cout << "deplacement interdit !" << endl;  }
                    else{
                    joueur.seTeleporter(p);
                    int tmp = joueur.getTeleportation();
                    joueur.setTeleportation(tmp- 1);
                    }
                }
                
            }
 
            //On test si le joueur à gagner un dollar
            if ( joueur.getScore() == 1 ) {
                if(p[pl.emplacementPortes.at(0)][pl.emplacementPortes.at(1)].getEtat().compare("-") == 0){
                    pl.openDoor(p, pl.emplacementPortes.at(0), pl.emplacementPortes.at(1));
                }
            }
            //si le joueur à 2 Dollar
            if ( joueur.getScore() == 2 ){
                if(p[pl.emplacementPortes.at(2)][pl.emplacementPortes.at(3)].getEtat().compare("-") == 0){
                    pl.openDoor(p, pl.emplacementPortes.at(2), pl.emplacementPortes.at(3));
                }
            }
            pl.updatePosition(p, joueur, currentX, currentY);
            pl.affichagePlateau(p);

            
    }
        
        //cout << "X == " << joueur.getX() << " Y == " << joueur.getY() << endl;
        if ( niveau <= argc ){
            cout << "Veuillez touchez une touche pour passer au niveau suivant" << endl;
            getchar();
            niveau++;
        }else{
            niveau++;
        }
        
        
       } 
   }
   /* Fin du jeu */
    }else{
        //creation du plateau -----> maintenant il faut le remplir
    static int hauteur, largeur;
    bool sortirBoucle = true;
    while(sortirBoucle){
        cout << "veuillez introduire une hauteur ..";
        cin >> hauteur;
        Case m[hauteur][LARGEUR];
        Plateau plateau(hauteur, LARGEUR);
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
        //pour sauvegarder
        cout << "Nom fichier .. "<< endl;
        cin >> nomF;
        plateau.sauvegarderPlateau(m, nomF);
        
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
    }
    return 0;
}
