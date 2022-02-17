#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class Enemy{
    public:
        static string race;
        static int baseHealth;
        int resist;
        double dmgNum;
    public:
        Enemy();
        ~Enemy();
        void setRace();
        static void setBaseHealth();
        void setDmgNums();
        void setDmgReduc();
        void printInfo(double cHealth);
};

#endif