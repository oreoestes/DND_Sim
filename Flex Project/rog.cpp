#include "rog.h"

Rogue::Rogue() : Char(){
    strength = 2;
    intel = 3;
    wisdom = 2;
    constitution = 2; 
    charisma = 2;
    dexterity = 4;
    dmgNums;
}

Rogue::~Rogue(){
    delete &strength, &intel, &wisdom, &constitution, &charisma, &dexterity, &dmgNums, &baseHealth, &baseMana;
};

void Rogue::setStrength(){
    strength += (rand() % 20) + 1;
};
void Rogue::setIntel(){
    intel += (rand() % 20) + 1;
};
void Rogue::setWis(){
    wisdom += (rand() % 20) + 1;
};
void Rogue::setCon(){
    constitution += (rand() % 20) + 1;
};
void Rogue::setCharis(){
    charisma += (rand() % 20) + 1;
};
void Rogue::setDex(){
    dexterity += (rand() % 20) + 1;
};
void Rogue::setDmgNum(){
    dmgNums = 25 + strength + (2 * dexterity);
};

void printInfo(Rogue &rog, int cHealth, int cMana){
    cout << rog.race << " Rogue" << endl;
    cout << "Health: " << cHealth << endl;
    cout << "Mana: " << cMana << endl;
}

void Rogue::backStab(){
    dmgNums = 70;
}

void printBase(Rogue &rog){
    rog.setCharis();
    rog.setCon();
    rog.setDex();
    rog.setStrength();
    rog.setIntel();
    rog.setWis();

    cout<< "\nAttributes:\n" << "Strength: " << rog.strength << "\nIntelligence: " << rog.intel << "\nDexterity: " << rog.dexterity 
        << "\nCharisma: " << rog.charisma << "\nConstitution: " << rog.constitution << "\nWisdom: " << rog.wisdom;
}