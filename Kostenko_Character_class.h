#ifndef __KOSTENKO_CLASS__
#define __KOSTENKO_CLASS__

#include <iostream>
#include <string>
#include <fstream>

class Kostenko_Character {
public:
    Kostenko_Character();
    ~Kostenko_Character();

    friend std::ostream& operator<< (std::ostream& out, const Kostenko_Character& character);
    friend std::istream& operator>> (std::istream& in, const Kostenko_Character& character);

    friend std::ifstream& operator>> (std::ifstream& in, const Kostenko_Character& character);
    friend std::ofstream& operator<< (std::ifstream& out, const Kostenko_Character& character);



private:
    std::string name;
    std::string surname;
    double height = 0;
    double weight = 0;
    int age = 0;

};



#endif