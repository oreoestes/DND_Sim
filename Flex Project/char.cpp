#include "char.h"

Char::Char(){
    name;
    race;
    baseHealth = 100;
    baseMana = 100;
}

Char::~Char(){
    delete &name, &race, &baseHealth, &baseMana; 
}






