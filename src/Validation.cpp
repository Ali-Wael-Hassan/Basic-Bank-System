#include "Validation.h"

bool Validation::isValidName(const std::string& s){
    for(auto& c : s){
        if(!isalpha(c)) return 0;
    }
    return 1;
}

bool Validation::isValidNum(int n){
    if(n <= 0) return 0;
    return 1;
}