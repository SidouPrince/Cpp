#include <iostream>
#include <fstream>
#include "Case.hpp"
#include "Monstre.hpp"
#include "const.hpp"
#include <bits/stdc++.h> 
using namespace std;
Monstre::Monstre(int r,int c){
	this->x = r;
	this->y = c;
}

///////////////////////////////////////////////////
void Monstre::move_haut(){
	this->x = this->x - 1 ;
}

void Monstre::move_bas(){
	this->x = this->x+1 ;
}

void Monstre::move_gauche(){
	this->y = this->y - 1 ;
}

void Monstre::move_droite(){
	this->y = this->y + 1 ;
}

 void Monstre::move_HD(){
 	this->x = this->x -1 ;
 	this -> y = y+1 ;
 }

 void Monstre::move_HG(){
 	this->x = this->x -1 ;
 	this -> y = y-1 ;
 }

void Monstre::move_BD(){
 	this->x = this->x +1 ;
 	this -> y = y+1 ;
 }

 void Monstre::move_BG(){
 	this->x = this->x +1 ;
 	this -> y = y-1 ;
 }

int Monstre::getX(){return this->x;}
int Monstre::getY(){return this->y;}
///////////////////////////////////////////////////////////////////////////////////
