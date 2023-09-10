#include "Kostenko_Character_class.h"
#include <iostream>
#include <fstream>

std::ostream& operator<< (std::ostream& out, const Kostenko_Character& character){
    out << "Name: " << character.name;
    out << "\nSurname: " << character.surname;
    out << "\nAge: " << character.age;
    out << "\nHeight: " << character.height;
    out << "\nWeight: " << character.weight;
    return out;
}


