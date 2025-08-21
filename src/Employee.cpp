#include "Employee.h"
#include "Validation.h"
#include "stdexcept"
#include <iostream>

Employee::Employee(std::string fst, std::string lst, int id, int age, std::string user, std::string password,  double salary, double bonus) : Person(fst,lst,id,age){
    if(!changeUser(user)) throw std::invalid_argument("Invalid User");
    if(!changePassword(password)) throw std::invalid_argument("Invalid Password");
    if(!setSalary(salary)) throw std::invalid_argument("Invalid Salary");
    assignBonus(bonus);
}

double Employee::calculateSalary() const{
    return this->bonus+this->salary;
}

bool Employee::changePassword(const std::string &newPassword){
    if(newPassword.empty()) return false;
    this->password = newPassword;
    return true;
}

bool Employee::changeUser(const std::string &newUser){
    if(newUser.empty()) return false;
    this->user = newUser;
    return true;
}
// setters
void Employee::assignBonus(double amount){
    this->bonus += amount;
}

bool Employee::setSalary(double salary){
    if(!Validation::isValidNum(salary)) return false;
    this->salary = salary;
    return true;
}
// getters
double Employee::getSalary() const{
    return this->salary;
}

double Employee::getBonus() const{
    return this->bonus;
}

std::string Employee::getPassword() const{
    return  this->password;
}

std::string Employee::getUser() const{
    return this->user;
}
// Display
void Employee::Display() const{
    std::cout << "Salary: " << this->salary << ", Bonus: " << this->bonus << '\n';
    std::cout << "Full Salary: " << calculateSalary() << '\n';
    Person::Display();
}
