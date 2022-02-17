#ifndef MAGE_H
#define MAGE_H
#include "char.h" 
#include <time.h> 

using namespace std;

class Mage : public Char{
    public:
        int strength;
        int intel;
        int wisdom;
        int constitution; 
        int charisma;
        int dexterity;
        int dmgNums;
    public:
        Mage();
        virtual ~Mage();
        void setStrength();
        void setIntel();
        void setWis();
        void setCon();
        void setCharis();
        void setDex();
        double setDmgNum();
        void fireBall();
        friend void printInfo(Mage &mag, int cHealth, int cMana); 
        friend void printBase(Mage &mag);
        void setBaseMana(){baseMana += 350;};
        void setBaseHealth() {baseHealth += 175;};
};

#endif