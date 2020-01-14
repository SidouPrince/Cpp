#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "const.hpp"
#include "Case.hpp"
#include "Fichier.hpp"
#include "Monstre.hpp"
#include "Plateau.hpp"
#include "joueur.hpp"
#include "joueur.hpp"
using namespace std;
int play(Joueur& joueur, Plateau& pl, Case(*p)[LARGEUR], int currentX, int currentY, char touche, vector<Monstre>& listeMonstres){
    if ( touche == 'h' )
            {
                if ( pl.validePosition(p, currentX - 1, currentY, joueur) ){
                    if (pl.isDollar(p, currentX -1, currentY)) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX -1, currentY)) joueur.setTeleportation((joueur.getTeleportation())+1);
                     joueur.haut();
                }
            }
            if ( touche == 'b' )
            {
                if ( pl.validePosition(p, currentX + 1, currentY, joueur) ){ 
                    if (pl.isDollar(p, currentX +1, currentY)) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX +1, currentY)) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.bas(20);
                }
            }
            if ( touche == 'd' )
            {
                
                if ( pl.validePosition(p, currentX, currentY + 1, joueur) ) {
                    if (pl.isDollar(p, currentX, currentY + 1)) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX, currentY + 1)) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.droit();
                }   
            }
            if ( touche == 'g' )
            {
                if ( pl.validePosition(p, currentX, currentY -1, joueur) ) {
                    if (pl.isDollar(p, currentX, currentY -1)) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX, currentY -1)) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.gauche();
                    
                } 
            }
             if ( touche == 'r' )
            {
                if ( pl.validePosition(p, currentX -1, currentY , joueur) ) {
                    if (pl.isDollar(p, currentX -1, currentY )) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX -1, currentY )) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.diagonalGH();
                    
                }
             }

              if ( touche == 'u' )
            {
                if ( pl.validePosition(p, currentX -1, currentY , joueur) ) {
                    if (pl.isDollar(p, currentX -1, currentY )) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX -1, currentY )) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.diagonalDH();
                    
                }
                
            }
            if ( touche == 'c' )
            {
                if ( pl.validePosition(p, currentX +1, currentY, joueur) ) {
                    if (pl.isDollar(p, currentX +1, currentY )) joueur.setScore((joueur.getScore())+1);
                    if (pl.isGueurchar(p, currentX +1, currentY )) joueur.setTeleportation((joueur.getTeleportation())+1);
                    joueur.diagonalGB();
                }
            
            }

            if ( touche == 'n' )
            {
                if ( pl.validePosition(p, currentX +1, currentY , joueur) ) {
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
            int entier = rand()%8;
            //deplacement monstre
            switch (entier)
            {
            case 0:
                for (int i = 0; i < pl.monstres.size(); i++)
                {
                   if(pl.validePositionM(p,(listeMonstres.at(i).getX() + 1),listeMonstres.at(i).getY()))  listeMonstres.at(i).move_bas();
                }
                 break;
            case 1:
                for (int i = 0; i < pl.monstres.size(); i++)
                {
                    if(pl.validePositionM(p,(listeMonstres.at(i).getX() - 1),listeMonstres.at(i).getY())) listeMonstres.at(i).move_haut();
                }
                 break;
            case 2:
                for (int i = 0; i < pl.monstres.size(); i++)
                {
                    if(pl.validePositionM(p,(listeMonstres.at(i).getX()) ,listeMonstres.at(i).getY() +1)) listeMonstres.at(i).move_droite();
                }
                 break;
            case 3:
                for (int i = 0; i < pl.monstres.size(); i++)
                {
                    if(pl.validePositionM(p,(listeMonstres.at(i).getX()),listeMonstres.at(i).getY() -1 )) listeMonstres.at(i).move_gauche();
                }
                 break;
            case 4:
                for (int i = 0; i < pl.monstres.size(); i++)
                {
                    if(pl.validePositionM(p,(listeMonstres.at(i).getX() + 1),listeMonstres.at(i).getY()+1)) listeMonstres.at(i).move_BD();
                }
                 break;
            case 5:
                for (int i = 0; i < pl.monstres.size(); i++)
                {
                   if(pl.validePositionM(p,(listeMonstres.at(i).getX() + 1),listeMonstres.at(i).getY() -1)) listeMonstres.at(i).move_BG();
                }
                 break;
            case 6:
                for (int i = 0; i < pl.monstres.size(); i++)
                {
                    if(pl.validePositionM(p,(listeMonstres.at(i).getX() - 1),listeMonstres.at(i).getY()+1)) listeMonstres.at(i).move_HD();
                }
                 break;
            case 7:
                for (int i = 0; i < pl.monstres.size(); i++)
                {
                    if(pl.validePositionM(p,(listeMonstres.at(i).getX() - 1),listeMonstres.at(i).getY()-1)) listeMonstres.at(i).move_HG();
                }
                
                break;
            
            default:
                break;
            }
            
           
}
#endif