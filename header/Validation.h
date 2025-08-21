#pragma once
#include <string>

class Validation{
    public:
        static bool isValidName(const std::string& s); 
        static bool isValidNum(int n);
        static bool isValidBalance(double amount);
        static bool isValidBalance(double balance, double amount);
};