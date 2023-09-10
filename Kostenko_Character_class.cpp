#include "Kostenko_Character_class.h"
#include <iostream>
#include <fstream>
#include <float.h>
#include "utils.h"


std::ostream& operator<< (std::ostream& out, const Kostenko_Character& character){
    out << "Name: " << character.name;
    out << "\nSurname: " << character.surname;
    out << "\nAge: " << character.age;
    out << "\nHeight: " << character.height;
    out << "\nWeight: " << character.weight;
    return out;
}

std::istream& operator>> (std::istream& in, Kostenko_Character& character){
    in.clear();
    in.ignore(INT_MAX, '\n');
    std::cout << "Input character's data:\n\tName: ";
    std::getline(in,  character.name);
    std::cout << "\n\tSurname: ";
    std::getline(in, character.surname);
    std::cout << "\n\tAge: ";
    character.age = GetRightValue(in, 0, INT_MAX);
    std::cout << "\n\tHeight: ";
    character.height = GetRightValue(in, 0.0, DBL_MAX);
    std::cout << "\n\tWeight: ";
    character.weight = GetRightValue(in, 0.0, DBL_MAX);
    return in;
}

std::ifstream& operator>> (std::ifstream& in, Kostenko_Character& character){
    std::getline(in, character.name, ',');
    std::getline(in, character.surname, ',');
 
    if (!valueInput(in, character.age, ',') || !valueInput(in, character.height, ',') || !valueInput(in, character.weight, ',')){
        in.setstate(std::ios::failbit);
    }
    return in;
}

std::ofstream& operator<< (std::ofstream& out, const Kostenko_Character& character){
    out << character.name << "," << character.surname << "," << character.age << "," << character.height << "," << character.weight << "," ;
    return out;
}
