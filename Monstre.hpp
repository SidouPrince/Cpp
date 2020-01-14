#ifndef MONSTRE_H
#define MONSTRE_H
#include <iostream>
#include "Case.hpp"
#include "const.hpp"
#include <bits/stdc++.h> 

class Monstre
{
private:
   int x;
   int y;
public:
    Monstre(int r, int c );
    int getX();
    int getY();
    void move_haut();
    void move_bas();
    void move_gauche();
    void move_droite();
    void move_HD();
    void move_HG();
     void move_BD();
     void move_BG();

   
};
#endif

