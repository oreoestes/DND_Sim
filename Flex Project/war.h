#ifndef WAR_H
#define WAR_H
#include "char.h"  
#include <time.h> 

using namespace std;

class Warrior : public Char{
    public:
        int strength;
        int intel;
        int wisdom;
        int constitution; 
        int charisma;
        int dexterity;
        int dmgNums;
    public:
        Warrior();
        virtual ~Warrior();
        void setStrength();
        void setIntel();
        void setWis();
        void setCon();
        void setCharis();
        void setDex();
        double setDmgNum(); 
        void headButt();
        friend void printInfo(Warrior &war, int cHealth, int cMana); 
        friend void printBase(Warrior &war);
        void setBaseMana(){baseMana += 50;};
        void setBaseHealth() {baseHealth += 500;};
};

#endif