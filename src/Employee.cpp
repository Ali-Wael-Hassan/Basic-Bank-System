#include "Employee.h"
#include "Validation.h"
#include "stdexcept"
#include <iostream>

Employee::Employee(std::string fst, std::string lst, int id, int age, double salary, double bonus) : Person(fst,lst,id,age){
    if(!setSalary(salary)) throw std::invalid_argument("Invalid Salary");
    assignBonus(bonus);
}

double Employee::calculateSalary() const{
    return this->bonus+this->salary;
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
// Display
void Employee::Display() const{
    std::cout << "Salary: " << this->salary << ", Bonus: " << this->bonus << '\n';
    std::cout << "Full Salary: " << calculateSalary() << '\n';
    Person::Display();
}
