#include "enemy.h"

string Enemy::race = "unknown";
int Enemy::baseHealth = 0;

Enemy::Enemy(){
    race;
    resist;
    dmgNum;
    baseHealth;
}

Enemy::~Enemy(){
    delete &race, &resist, &dmgNum, &baseHealth;
}

void Enemy::setRace(){
    string arr[] = {"Goblin", "Orc", "Dark Elf", "Treant"};
    int raceChoice = rand() % 4 + 1;
    race = arr[raceChoice];
}

void Enemy::setBaseHealth(){
    if(race == "Goblin")
        baseHealth = 200;
    else if(race == "Orc")
        baseHealth = 350;
    else if(race == "Dark Elf")
        baseHealth = 275;
    else if(race == "Treant")
        baseHealth = 400;
}

void Enemy::setDmgNums(){
    if(race == "Goblin")
        dmgNum = 3 + (.15 * baseHealth);
    else if(race == "Orc")
        dmgNum = 5 + (.06 * baseHealth);
    else if(race == "Dark Elf")
        dmgNum = 4 + (.08 * baseHealth);
    else if(race == "Treant")
        dmgNum = 2 + (.1 * baseHealth);
}

void Enemy::setDmgReduc(){
    if(race == "Goblin")
        resist = 2;
    else if(race == "Orc")
        resist = 5;
    else if(race == "Dark Elf")
        resist = 3;
    else if(race == "Treant")
        resist = 9;
}

void Enemy::printInfo(double cHealth){
    cout << race << endl;
    cout << "Health: " << cHealth << endl; 
}
