#include <iostream>
#include "Case.hpp"
#include "Plateau.hpp"
#include "Joueur.hpp"
#include "Fichier.hpp"
#include "game.hpp"
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
    cout << "3- charger une partie !" << endl;
    cin >> choix;
    /* Debut du jeu  */
    if ( choix == 1 ){
   if ( argc > 1 )
   {
       //il y a aumoins un nom de fichier
       int niveau = 1;
       int xLoc, yLoc;
       while ( niveau <= argc )
       {
        Case p[getHauteur(argv[niveau])][LARGEUR];
        uploadLevel(p, argv[niveau]);//charger le plateau du fichier sur la matrice
        Plateau pl(getHauteur(argv[niveau]), LARGEUR);
        xLoc = pl.getX(p);
        yLoc = pl.getY(p);
        //recuperation des portes
        pl.getXYportes(p);
        //creation du joueur
        Joueur joueur(xLoc, yLoc, 0, 0,0);
        
        //la boucle d'interaction
        while (joueur.getGameOver()!= 1 & (touche = getchar()) != 'q' )
        {
            cout << "Score == " << joueur.getScore() << endl;
            cout << "Teleportations == " << joueur.getTeleportation() << endl;
            int currentX = pl.getX(p);
            int currentY = pl.getY(p);
            pl.monstres.clear();
            pl.emplacementMonstres.clear();
            //coordonnees monstres
            pl.getXYMonstres(p);
            pl.positionsToMonstre();
            
            play(joueur, pl, p, currentX, currentY, touche, pl.monstres);
            
            if ( touche == 's' )
            {
                //sauvegarder la partie
                pl.sauvegardePartie(p,joueur.getScore(), joueur.getTeleportation(), argv, niveau, argc);
                niveau = argc+ 40;
                break;  
            }
            
             //on test si le joueur à franchi la porte
            if ( pl.isOpen(p, joueur.getX(), joueur.getY()) ){
                break;   
            }else{
            }
             
            pl.affichagePlateau(p);
            pl.updatePositionM(p,pl.monstres,pl.emplacementMonstres);
            pl.updatePosition(p, joueur, currentX, currentY);
        }
        if ( niveau <= argc && touche != 'q' && joueur.getGameOver() != 1){
            cout << "Veuillez touchez une touche pour passer au niveau suivant" << endl;
            getchar();
            niveau++;
        }else{
            if (joueur.getGameOver() == 1) cout << "Game overrr ! " << endl;
            niveau = niveau + 50;
        }
       }   
       }
   /* Fin du jeu */
    }else if(choix == 2){
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
    }else{
           //on test si un fichier sauvegarde existe deja
           ifstream fichier("Niveaux/plateau.txt");
           ifstream fichierD("Niveaux/donnees.txt");
           if (fichier)/*une partie sauvegardée existe deja*/
           {
               
               int score, teleportation;
               string ligne;
               string argv[10];
               int argc = 1;

               getline(fichierD, ligne);
               score = stoi(ligne);
               getline(fichierD, ligne);
               teleportation = stoi(ligne);
               int i = 1;
               argv[0] = "plateau.txt";
                while ( getline(fichierD, ligne))
                {
                    argv[i] = ligne;//contient les niveaux
                    i++;
                    argc++;
                }
                int niveau = 0;
                while ( niveau <= argc )
                {
                    int xLoc, yLoc;
                    Case p[getHauteur(argv[niveau])][LARGEUR];
                    uploadLevel(p, argv[niveau]);//charger le plateau du fichier sur la matrice
                    Plateau pl(getHauteur(argv[niveau]), LARGEUR);
                    //pl.affichagePlateau(p);
                    xLoc = pl.getX(p);
                    yLoc = pl.getY(p);
                    //recuperation des portes
                    pl.getXYportes(p);
                    //coordonnees monstres
                    cout << "av" << endl;
        pl.getXYMonstres(p);
        pl.positionsToMonstre();
        cout << "ap" << endl;
                    //creation du joueur
                    Joueur joueur(xLoc, yLoc, 0, 0,0);
                    //la boucle d'interaction
        while (joueur.getGameOver() != 1 & (touche = getchar()) != 'q' )
        {
            cout << "Score == " << joueur.getScore() << endl;
            cout << "Teleportations == " << joueur.getTeleportation() << endl;
            int currentX = pl.getX(p);
            int currentY = pl.getY(p);
            play(joueur, pl, p, currentX, currentY, touche, pl.monstres);
            //on test si le joueur à franchi la porte
            if ( pl.isOpen(p, joueur.getX(), joueur.getY()) ){
                break;   
            }else{
            }
            pl.updatePosition(p, joueur, currentX, currentY); 
            pl.affichagePlateau(p); 
        }
        if ( niveau <= argc && touche != 'q' && joueur.getGameOver() != 1){
            cout << "Veuillez touchez une touche pour passer au niveau suivant" << endl;
            getchar();
            niveau++;
        }else{
            if ( joueur.getGameOver() == 1 ) cout << "Game Over !" << endl;
            niveau = niveau +40;
             //supprimer les deux fichiers plateau et donnees
                if( remove( "Niveaux/plateau.txt" ) != 0 )
                perror( "Error deleting file" );
                else
                puts( "File successfully deleted" );
                if( remove( "Niveaux/donnees.txt" ) != 0 )
                perror( "Error deleting file" );
                else
                puts( "File successfully deleted" );
        }
           }
           
    }else{
        cout << "Pa de partie sauvegardée "<< endl;
    }
}
    
    return 0;
}
