#include "war.h"

Warrior::Warrior() : Char(){
    strength = 4;
    intel = 1;
    wisdom = 1;
    constitution = 3; 
    charisma = 2;
    dexterity = 3;
    dmgNums;
}

Warrior::~Warrior(){
    delete &strength, &intel, &wisdom, &constitution, &charisma, &dexterity, &dmgNums, &baseHealth, &baseMana;
};

void Warrior::setStrength(){
    strength += (rand() % 20) + 1;
};
void Warrior::setIntel(){
    intel += (rand() % 20) + 1;
};
void Warrior::setWis(){
    wisdom += (rand() % 20) + 1;
};
void Warrior::setCon(){
    constitution += (rand() % 20) + 1;
};
void Warrior::setCharis(){
    charisma += (rand() % 20) + 1;
};
void Warrior::setDex(){
    dexterity += (rand() % 20) + 1;
};
double Warrior::setDmgNum(){
    dmgNums = 15 + (2 * strength) + dexterity;
    return dmgNums;
};

void Warrior::headButt(){
    dmgNums = 95;
}

void printInfo(Warrior &war, int cHealth, int cMana){
    cout << war.race << " Warrior" << endl;
    cout << "Health: " << cHealth << endl;
    cout << "Mana: " << cMana << endl;
}

void printBase(Warrior &war){
    war.setCharis();
    war.setCon();
    war.setDex();
    war.setStrength();
    war.setIntel();
    war.setWis();
    
    cout<< "\nAttributes:\n" << "Strength: " << war.strength << "\nIntelligence: " << war.intel << "\nDexterity: " << war.dexterity 
        << "\nCharisma: " << war.charisma << "\nConstitution: " << war.constitution << "\nWisdom: " << war.wisdom;
}

