#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>

// Function to input value to a variable and to check if it fits the requirements of variable's type.
template <typename T>
bool valueInput(std::istream& in, T& checkingValue, char delim = '\n'){
    if (!(in >> checkingValue) || ((in.peek() != delim) && (in.peek() != ' '))|| in.fail()){
        checkingValue = -1;
        in.clear();
        in.ignore(INT_MAX, delim);
        return false;
    } else {
        // If there is any delimeteres except for '\n' advance the input by one character.
        if (delim != '\n')
            in.rdbuf() -> std::streambuf::sbumpc();
        return true;
    }
}

// Function same to valueInput(), but checks if the input value fits in allowed limits
template <typename T>
T GetRightValue(std::istream& in, T min, T max){
    T checkingValue;
    while (!valueInput(in, checkingValue) || (checkingValue < min) || (checkingValue > max)){
        std::cout<<"INPUT ERROR: Invalid value. Try again.\n";
    }
    return checkingValue;
}


#endif