#ifndef CHAR_H
#define CHAR_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Char{
    public:
        string name;
        string race;
        double baseHealth;
        double baseMana;
    public:
        Char();
        virtual ~Char();
        virtual void setBaseHealth() = 0;
        virtual void setBaseMana() = 0;
};

#endif
