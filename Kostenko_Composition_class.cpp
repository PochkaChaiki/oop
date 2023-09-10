#include "Kostenko_Composition_class.h"
#include "Kostenko_Character_class.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "utils.h"

Kostenko_Composition::~Kostenko_Composition(){
    for(auto& it : characters)
        delete it;
}

void Kostenko_Composition::PrintCharacters(){
    std::cout <<"\n#---------------------------------#\n";
    std::cout << "Characters in composition: \n";
    std::cout << "#- - - - - - - - - - - - - - - - - #\n";
    for (auto& ptr_character: characters)
        std::cout << *ptr_character << "\n#- - - - - - - - - - - - - - - - - #\n";
}

void Kostenko_Composition::ClearCharacters(){
    for (auto& ptr_character: characters)
        delete ptr_character;
    characters.clear();
}

std::ifstream& operator>> (std::ifstream& in, Kostenko_Composition& composition){
    
    if (!in){
        std::cout << "READ ERROR: Failed to open file.\n\n";
        return in;
    }
    composition.ClearCharacters();
    int amount(0);
    valueInput(in, amount, ',');
    for (int i(0); i < amount; ++i){
        composition.AddNewCharacter(in);
        if (in.fail()){
            std::cout<<"FILE READ ERROR: Failed to read character due to file's damage."<<std::endl;
            return in;
        }
    } 
    return in;
}

std::ofstream& operator<< (std::ofstream& out, const Kostenko_Composition& composition){
    if (!out){
        std::cout << "WRITE ERROR: Failed to open file.\n";
        return out;
    }
    out << composition.characters.size() << ",";
    for (const auto &ptr : composition.characters)
        out << *ptr;
    return out;
}

