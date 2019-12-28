#ifndef CASE_H
#define CASE_H

#include <iostream>
using namespace std;

class Case
{
    int const REUMUS = 0;
    int const DIAMS = 1;
    int const GEURCHARS = 2;
    int const TEUPORS = 3;
    int const EMPTY  = 4;
    int const PLAYER = 5;
    int const STREUMON = 6;
private:
    // enum etat {REUMUS, DIAMS, GEURCHARS, TEUPORS, EMPTY};
    int etat;

public:
    Case(int e);
    Case();
    
    void setEtat(int etat);
    string getEtat();
    
};

#endif