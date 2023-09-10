#ifndef __KOSTENKO_COMPOSITION_CLASS__
#define __KOSTENKO_COMPOSITION_CLASS__

#include <iostream>
#include <fstream>
#include <vector>
#include "Kostenko_Character_class.h"

class Kostenko_Composition{
public:

    ~Kostenko_Composition();

    template<typename T>
    void AddNewCharacter(T& in){
        Kostenko_Character* character = new Kostenko_Character;
        in >> *character;
        characters.push_back(character);
    }
    void PrintCharacters();
    void ClearCharacters();

    friend std::ifstream& operator>> (std::ifstream& in, Kostenko_Composition& composition);
    friend std::ofstream& operator<< (std::ofstream& out, const Kostenko_Composition& composition);

private:
    std::vector<Kostenko_Character*> characters;
};


#endif