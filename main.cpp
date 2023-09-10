#include <iostream>
#include <fstream>
#include <string>
#include "Kostenko_Character_class.h"
#include "Kostenko_Composition_class.h"
#include "utils.h"

void printMenu();

int main(){
    int option(-1);
    Kostenko_Composition Composition;
    while (option){
        printMenu();
        switch(option){
            case 0: return 0;
            case 1:
                Composition.AddNewCharacter(std::cin);
                break;
            case 2:
                Composition.PrintCharacters();
                break;
            case 3:{
                std::string filename;
                std::cout << "Enter filename: ";
                std::getline(std::cin, filename);
                std::ifstream file (filename, std::ifstream::in);
                file >> Composition;
                file.close();
            } break;
            case 4:{
                std::string filename;
                std::cout << "Enter filename: ";
                std::getline(std::cin, filename);
                std::ofstream file (filename, std::ofstream::out);
                file << Composition;
                file.close();
            } break;
            case 5:
                Composition.ClearCharacters();
                break;
            default: break;
        }
    }
    return 0;
}

void printMenu(){
    std::cout << "\n\tMENU:\n";
    std::cout << "\t 0 - Exit program.\n";
    std::cout << "\t 1 - Add new character.\n";
    std::cout << "\t 2 - Show all characters.\n";
    std::cout << "\t 3 - Load characters from file.\n";
    std::cout << "\t 4 - Save characters to file.\n";
    std::cout << "\t 5 - Clear all characters.\n";
}