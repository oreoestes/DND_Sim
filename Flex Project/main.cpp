#include "rog.h"
#include "mage.h"
#include "war.h"
#include "enemy.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

void printIntro();
void printScene();
void getItems();
void updateItems();
void dropItem();

vector<string> ItemVec;

int main(){
    srand(time(NULL));

    char playerClass, pRace, combatChoice, itemChoice;

    double pDmgNums, tDmgDone, eDmgNums, eRes;
    double pHealth, pMana, eHealth;
    
    bool pDead = 0, eDead = 0;

    int randItem;

    string itemArr[4] = {"Scepter", "Longbow", "Heavy Club", "Tough Bark"};
    string invFull, dropName;

    printIntro();
    cin >> playerClass;

        switch(playerClass){
            case 'r': {
                Rogue player1;

                player1.setDmgNum();
                player1.setBaseMana();
                player1.setBaseHealth();
                
                pDmgNums = player1.dmgNums;
                pHealth = player1.baseHealth;
                pMana = player1.baseMana;

                cout << "Select a race: Human (H)\tDwarf (D)\tElf (E)\n";
                cin >> pRace;

                if(pRace == 'H' || pRace == 'h')
                    player1.race = "Human";
                else if(pRace == 'D' || pRace == 'd')
                    player1.race = "Dwarf";            
                else if(pRace == 'E' || pRace == 'e')
                    player1.race = "Elf";

                cout << "Enter a name: ";
                cin >> player1.name;

                cout << "Nice to meet you, " + player1.name + ". Be safe Hero!" << endl << endl;

                printBase(player1);

                printScene();
                cin >> combatChoice;

                Enemy enem;
                
                enem.setRace();
                enem.setBaseHealth();
                enem.setDmgNums();
                enem.setDmgReduc();

                eHealth = enem.baseHealth;
                eRes = enem.resist;
                eDmgNums = enem.dmgNum;
                tDmgDone = pDmgNums - eRes;

                while (pDead == 0){
                    if(pHealth <= 0){
                        cout << "You have died! Better luck next time hero." << endl;
                        pDead = 1;
                    }

                    if(eHealth <= 0){
                        randItem = rand() % 4;
                        cout << "You have slain the enemy!" << endl;
                        cout << enem.race << " has dropped a(n) " << itemArr[randItem] << endl
                                << "Would you like to pick it up? (y/n): ";
                                cin >> itemChoice;
                            if(itemChoice == 'y'){
                                ItemVec.push_back(itemArr[randItem]);
                                updateItems();
                            }
                        new Enemy; 
                        enem.setRace();
                        enem.setBaseHealth();
                        enem.setDmgNums();
                        enem.setDmgReduc();
                        eHealth = enem.baseHealth;

                        cout << "A new enemy has appeared!\n"
                            << "What will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                        cin >> combatChoice;
                    }

                    if(combatChoice == 'f'){
                        player1.~Rogue();
                        ItemVec.erase(ItemVec.begin(), ItemVec.end());
                        break;   
                    }   

                    cin >> combatChoice;
                    cout << endl;

                    switch(combatChoice){
                        case 'a':{
                            enem.printInfo((double) eHealth);
                            cout << endl;
                            printInfo(player1, (double) pHealth, (double) pMana);
                            cout << "Damage Done: " << (tDmgDone) << endl;
                            cout << "Damage Taken: " << (eDmgNums) << endl;

                            eHealth = eHealth - tDmgDone;
                            pHealth = pHealth - eDmgNums;
                            if(pMana < player1.baseMana)
                                pMana += 15;
                            else if(pMana == player1.baseMana)
                                pMana = player1.baseMana;
                            cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                            break;
                        }
                        case 'r':{
                            if(pMana >= 65){
                                player1.backStab();
                                pDmgNums = player1.dmgNums;
                                enem.printInfo((double) eHealth);
                                cout << endl;
                                printInfo(player1, (double) pHealth, (double) pMana);
                                cout << "Damage Done: " << (pDmgNums - eRes) << endl;
                                cout << "Damage Taken: " << (eDmgNums) << endl;

                                eHealth = eHealth - pDmgNums + eRes;
                                pHealth = pHealth - eDmgNums;
                                pMana = pMana - 65;
                                
                                player1.setDmgNum();
                                pDmgNums = player1.dmgNums;
                            }
                            else
                                cout << "OUT OF MANA!" << endl;

                            cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                            break;
                        }
                        case 'b':{
                            getItems();
                            break;
                        }
                        case 'd':{
                            cout << "Which item would you like to drop?: ";
                            dropItem();
                            break;
                        }
                        case 'h':{
                            pHealth += 55;
                            pMana = pMana - 15;
                            enem.printInfo((double) eHealth);
                            cout << endl;
                            printInfo(player1, (double) pHealth, (double) pMana);
                            cout << "Healed for: 55" << endl;
                            cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                            break; 
                        }

                    }
        
                }
                break;
            }
            case 'm': {
                Mage player2;

                player2.setDmgNum();
                player2.setBaseMana();
                player2.setBaseHealth();
                
                pDmgNums = player2.dmgNums;
                pHealth = player2.baseHealth;
                pMana = player2.baseMana;

                cout << "Select a race: Human (H)\tDwarf (D)\tElf (E)\n";
                cin >> pRace;

                if(pRace == 'H' || pRace == 'h')
                    player2.race = "Human";
                else if(pRace == 'D' || pRace == 'd')
                    player2.race = "Dwarf";            
                else if(pRace == 'E' || pRace == 'e')
                    player2.race = "Elf";

                cout << "Enter a name: ";
                cin >> player2.name;

                cout << "Nice to meet you, " + player2.name + ". Be safe Hero!" << endl << endl;

                printBase(player2);

                printScene();
                cin >> combatChoice;
                Enemy enem;
                enem.setRace();
                enem.setBaseHealth();
                enem.setDmgNums();
                enem.setDmgReduc();

                eHealth = enem.baseHealth;
                eRes = enem.resist;
                eDmgNums = enem.dmgNum;
                tDmgDone = pDmgNums - eRes;

                while (pDead == 0){
                    if(pHealth <= 0){
                        cout << "You have died! Better luck next time hero." << endl;
                        pDead = 1;
                    }

                    if(eHealth <= 0){
                        randItem = rand() % 4;
                        cout << "You have slain the enemy!" << endl;
                        cout << enem.race << " has dropped a(n) " << itemArr[randItem] << endl
                                << "Would you like to pick it up? (y/n): ";
                                cin >> itemChoice;
                            if(itemChoice == 'y'){
                                ItemVec.push_back(itemArr[randItem]);
                                updateItems();
                            }
                        new Enemy; 
                        enem.setRace();
                        enem.setBaseHealth();
                        enem.setDmgNums();
                        enem.setDmgReduc();
                        eHealth = enem.baseHealth;

                        cout << "A new enemy has appeared!\n"
                            << "What will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                        cin >> combatChoice;
                    }

                    if(combatChoice == 'f'){
                        player2.~Mage();
                        ItemVec.erase(ItemVec.begin(), ItemVec.end());
                        break;   
                    }   

                    cin >> combatChoice;
                    cout << endl;

                    switch(combatChoice){
                        case 'a':{
                            enem.printInfo((double) eHealth);
                            cout << endl;
                            printInfo(player2, (double) pHealth, (double) pMana);
                            cout << "Damage Done: " << (tDmgDone) << endl;
                            cout << "Damage Taken: " << (eDmgNums) << endl;

                            eHealth = eHealth - tDmgDone;
                            pHealth = pHealth - eDmgNums;
                            if(pMana < player2.baseMana)
                                pMana += 15;
                            else if(pMana == player2.baseMana)
                                pMana = player2.baseMana;
                            cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                            break;
                        }
                        case 'r':{
                            if(pMana >= 65){
                                player2.fireBall();
                                pDmgNums = player2.dmgNums;
                                enem.printInfo((double) eHealth);
                                cout << endl;
                                printInfo(player2, (double) pHealth, (double) pMana);
                                cout << "Damage Done: " << (pDmgNums - eRes) << endl;
                                cout << "Damage Taken: " << (eDmgNums) << endl;

                                eHealth = eHealth - pDmgNums + eRes;
                                pHealth = pHealth - eDmgNums;
                                pMana = pMana - 65;
                                
                                player2.setDmgNum();
                                pDmgNums = player2.dmgNums;
                            }
                            else
                                cout << "OUT OF MANA!" << endl;

                            cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                            break;
                        }
                        case 'b':{
                            getItems();
                            break;
                        }
                        case 'd':{
                            cout << "Which item would you like to drop?: ";
                            dropItem();
                            break;
                        }
                        case 'h':{
                            pHealth += 65;
                            pMana = pMana - 15;
                            enem.printInfo((double) eHealth);
                            cout << endl;
                            printInfo(player2, (double) pHealth, (double) pMana);
                            cout << "Healed for: 65" << endl;
                            cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                            break; 
                        }

                    }
                }
                break;
            }
            case 'w': {
                Warrior player3;

                player3.setDmgNum();
                player3.setBaseMana();
                player3.setBaseHealth();
                
                pDmgNums = player3.dmgNums;
                pHealth = player3.baseHealth;
                pMana = player3.baseMana;

                cout << "Select a race: Human (H)\tDwarf (D)\tElf (E)\n";
                cin >> pRace;

                if(pRace == 'H' || pRace == 'h')
                    player3.race = "Human";
                else if(pRace == 'D' || pRace == 'd')
                    player3.race = "Dwarf";            
                else if(pRace == 'E' || pRace == 'e')
                    player3.race = "Elf";

                cout << "Enter a name: ";
                cin >> player3.name;

                cout << "Nice to meet you, " + player3.name + ". Be safe Hero!" << endl << endl;

                printBase(player3);

                printScene();
                cin >> combatChoice;
                Enemy enem;
                enem.setRace();
                enem.setBaseHealth();
                enem.setDmgNums();
                enem.setDmgReduc();

                eHealth = enem.baseHealth;
                eRes = enem.resist;
                eDmgNums = enem.dmgNum;
                tDmgDone = pDmgNums - eRes;

                while (pDead == 0){
                    if(pHealth <= 0){
                        cout << "You have died! Better luck next time hero." << endl;
                        pDead = 1;
                    }

                    if(eHealth <= 0){
                        randItem = rand() % 4;
                        cout << "You have slain the enemy!" << endl;
                        cout << enem.race << " has dropped a(n) " << itemArr[randItem] << endl
                                << "Would you like to pick it up? (y/n): ";
                                cin >> itemChoice;
                            if(itemChoice == 'y'){
                                ItemVec.push_back(itemArr[randItem]);
                                updateItems();
                            }
                        new Enemy; 
                        enem.setRace();
                        enem.setBaseHealth();
                        enem.setDmgNums();
                        enem.setDmgReduc();
                        eHealth = enem.baseHealth;

                        cout << "A new enemy has appeared!\n"
                            << "What will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                        cin >> combatChoice;
                    }

                    if(combatChoice == 'f'){
                        player3.~Warrior();
                        ItemVec.erase(ItemVec.begin(), ItemVec.end());
                        break;   
                    }   

                    cin >> combatChoice;
                    cout << endl;

                    switch(combatChoice){
                        case 'a':{
                            enem.printInfo((double) eHealth);
                            cout << endl;
                            printInfo(player3, (double) pHealth, (double) pMana);
                            cout << "Damage Done: " << (tDmgDone) << endl;
                            cout << "Damage Taken: " << (eDmgNums) << endl;

                            eHealth = eHealth - tDmgDone;
                            pHealth = pHealth - eDmgNums;
                            if(pMana < player3.baseMana)
                                pMana += 15;
                            else if(pMana == player3.baseMana)
                                pMana = player3.baseMana;
                            cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                            break;
                        }
                        case 'r':{
                            if(pMana >= 65){
                                player3.headButt();
                                pDmgNums = player3.dmgNums;
                                enem.printInfo((double) eHealth);
                                cout << endl;
                                printInfo(player3, (double) pHealth, (double) pMana);
                                cout << "Damage Done: " << (pDmgNums - eRes) << endl;
                                cout << "Damage Taken: " << (eDmgNums) << endl;

                                eHealth = eHealth - pDmgNums + eRes;
                                pHealth = pHealth - eDmgNums;
                                pMana = pMana - 65;
                                
                                player3.setDmgNum();
                                pDmgNums = player3.dmgNums;
                            }
                            else
                                cout << "OUT OF MANA!" << endl;

                            cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                            break;
                        }
                        case 'b':{
                            getItems();
                            break;
                        }
                        case 'd':{
                            cout << "Which item would you like to drop?: ";
                            dropItem();
                            break;
                        }
                        case 'h':{
                            pHealth += 45;
                            pMana = pMana - 10;
                            enem.printInfo((double) eHealth);
                            cout << endl;
                            printInfo(player3, (double) pHealth, (double) pMana);
                            cout << "Healed for: 45" << endl;
                            cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
                            break; 
                        }

                    }
                }
            }
        }
    return 0;
}   

void getItems(){
    string item;
    int count = 1;
    ifstream fromFile;
    fromFile.open("inventory.txt");
    if(fromFile.is_open()){
        while(getline(fromFile, item)){
            cout << count << ". " << item << endl;
            count++;
        }
        count = 1;
    }
    fromFile.close();
    cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
}

void updateItems(){
    size_t i;
    ofstream oFile; 
    oFile.open("inventory.txt");
    if(oFile.is_open()){
        for(i = 0; i<ItemVec.size(); i++){
             oFile<<ItemVec.at(i)<<endl;
        }

    oFile.close();
    }
    cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
}

void dropItem(){
    int z, x;
        x = ItemVec.size();
        cout<<"Number: "; cin>>z;
        if(!(z>=1 && z<=x)){
        cout<<"Invalid Entry";
        }
        else{
        cout<<"You dropped "<<ItemVec.at(z-1)<<"."<<endl;
        ItemVec.erase(ItemVec.begin()+(z-1));
        updateItems(); 
    }
    cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";
}

void printIntro(){
    cout << "Welcome to the Dungeons and Dragons Character Simulator!\n"
         << "Here you will be able to test combat based on class and stats against different enemies.\n"
         << "Each enemy defeated will allow you to pick up an item.\n"
         << "GOOD LUCK AND HAVE FUN!!\n\n"
         << "Select a class: Rogue (R) \tWarrior (W) \tMage (M)\n";
}

void printScene(){
    cout << "\n\nIt's been centuries sinc the last time Tiamat roamed this world. We all presumed "
         << "her to be dead, yet the earth is once more \nshaking beneath our feet and strange winds blow once again.";
    cout << "May the Gods bless your travels hero, I pray you can help us all before it's too late.\n\n";
    cout << "TWO DAYS LATER\n" << "............\n";
    cout << "You are now two days into your trip traveling through the forbidden forests on your way to the Great City of Phlan.\n"
         <<"As you make your way through the forest you encounter an enemy!\n\n";
    cout << "\nWhat will you do? (attack - a)  (special ability - r)  (heal - h)  (exit - f)  (inventory - b)  (drop item - d): ";   
}