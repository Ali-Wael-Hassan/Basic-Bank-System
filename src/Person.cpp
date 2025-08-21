#include "Person.h"
#include "Validation.h"
#include <stdexcept>
#include <iostream>
#include "FullNameFormatter.h"

Person::Person(std::string fst, std::string lst, int id, int age){
    if(!setFirstName(fst)) throw std::invalid_argument("Invalid First Name");
    if(!setLastName(lst)) throw std::invalid_argument("Invalid Last Name");
    if(!setId(id)) throw std::invalid_argument("Invalid ID");
    if(!setAge(age)) throw std::invalid_argument("Invalid Age");
}
//setters
bool Person::setFirstName(const std::string& fst){
    if(!Validation::isValidName(fst)) return false;
    this->fst = fst;
    return true;
}
    
bool Person::setLastName(const std::string& lst){
    if(!Validation::isValidName(lst)) return false;
    this->lst = lst;
    return true;
}

bool Person::setId(int id){
    if(!Validation::isValidNum(id)) return false;
    this->id = id;
    return true;
}

bool Person::setAge(int age){
    if(!Validation::isValidNum(age)) return false;
    this->age = age;
    return true;
}
// getters
std::string Person::getFirstName() const{
    return this->fst;
}

std::string Person::getLastName() const{
    return this->lst;
}

int Person::getId() const{
    return this->id;
}

int Person::getAge() const{
    return this->age;
}
//Display
void Person::Display() const
{
    std::cout << "Full Name: " << FullNameFormatter::fullName(this->fst,this->lst) << '\n';
    std::cout << "ID: " << this->id << ", Age: " << this->age << '\n';
}