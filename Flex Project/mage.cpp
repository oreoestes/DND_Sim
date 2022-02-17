#include "mage.h"

Mage::Mage() : Char(){
    strength = 1;
    intel = 4;
    wisdom = 3;
    constitution = 2; 
    charisma = 2;
    dexterity = 2;
    dmgNums;
}

Mage::~Mage(){
    delete &strength, &intel, &wisdom, &constitution, &charisma, &dexterity, &dmgNums, &baseHealth, &baseMana;
};

void Mage::setStrength(){
    strength += (rand() % 20) + 1;
};
void Mage::setIntel(){
    intel += (rand() % 20) + 1;
};
void Mage::setWis(){
    wisdom += (rand() % 20) + 1;
};
void Mage::setCon(){
    constitution += (rand() % 20) + 1;
};
void Mage::setCharis(){
    charisma += (rand() % 20) + 1;
};
void Mage::setDex(){
    dexterity += (rand() % 20) + 1;
};
double Mage::setDmgNum(){
    dmgNums = 35 + wisdom + (2 * intel);
    return dmgNums;
};

void Mage::fireBall(){
    dmgNums = 110;
}

void printInfo(Mage &mag, int cHealth, int cMana){
    cout << mag.race << " Mage" << endl;
    cout << "Health: " << cHealth << endl;
    cout << "Mana: " << cMana << endl;
}


void printBase(Mage &mag){
    mag.setCharis();
    mag.setCon();
    mag.setDex();
    mag.setStrength();
    mag.setIntel();
    mag.setWis();

    cout<< "\nAttributes:\n" << "Strength: " << mag.strength << "\nIntelligence: " << mag.intel << "\nDexterity: " << mag.dexterity 
        << "\nCharisma: " << mag.charisma << "\nConstitution: " << mag.constitution << "\nWisdom: " << mag.wisdom;
}

