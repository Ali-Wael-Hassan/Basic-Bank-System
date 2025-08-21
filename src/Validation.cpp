#include "Validation.h"

bool Validation::isValidName(const std::string& s){
    if(s.empty()) return false;
    for(auto& c : s){
        if(!isalpha(c)) return false;
    }
    return true;
}

bool Validation::isValidNum(int n){
    return n > 0;
}

bool Validation::isValidBalance(double amount){
    if(amount < 0) return false;
    return true;
}

bool Validation::isValidBalance(double balance, double amount){
    if(!isValidBalance(amount) || amount > balance) return false;
    return true;
}
