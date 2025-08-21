#include "CustomerAccount.h"
#include "Validation.h"
#include <stdexcept>
#include <iostream>

CustomerAccount::CustomerAccount(std::string fst, std::string lst, int id, int age ,const std::string &user, const std::string &password, double balance):Person(fst,lst,id,age){
    if(!changePassword(password)) throw std::invalid_argument("Invalid Password");
    if(!changeUser(user)) throw std::invalid_argument("Invalid User");
    if(!deposit(balance)) throw std::invalid_argument("Invalid Balance");
}

bool CustomerAccount::deposit(double amount)
{
    if(!Validation::isValidBalance(amount) || amount == 0) return false;
    this->balance += amount;
    return true;
}

bool CustomerAccount::withdraw(double amount){
    if(!Validation::isValidBalance(this->balance, amount) || amount == 0) return false;
    this->balance -= amount;
    return true;
}

bool CustomerAccount::changePassword(const std::string &newPassword){
    if(newPassword.empty()) return false;
    this->password = newPassword;
    return true;
}

bool CustomerAccount::changeUser(const std::string &newUser){
    if(newUser.empty()) return false;
    this->user = newUser;
    return true;
}
// getters
double CustomerAccount::getBalance(){
    return this->balance;
}
std::string CustomerAccount::getPassword() const{
    return this->password;
}
std::string CustomerAccount::getUser() const{
    return this->user;
}
// Display
void CustomerAccount::Display() const{
    std::cout << "User: " << this->user << ", Balance: " << this->balance << '\n';
    Person::Display();
}