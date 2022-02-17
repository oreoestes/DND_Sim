#ifndef ROG_H
#define ROG_H
#include "char.h"  
#include <time.h> 

using namespace std;

class Rogue : public Char{
    public:
        int strength;
        int intel;
        int wisdom;
        int constitution; 
        int charisma;
        int dexterity;
        int dmgNums;
    public:
        Rogue();
        virtual ~Rogue();
        void setStrength();
        void setIntel();
        void setWis();
        void setCon();
        void setCharis();
        void setDex();
        void setDmgNum(); 
        void backStab();
        friend void printInfo(Rogue &rog, int cHealth, int cMana); 
        friend void printBase(Rogue &rog);
        void setBaseMana(){baseMana += 200;};
        void setBaseHealth(){baseHealth += 300;};
};

#endif