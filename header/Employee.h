#pragma once
#include "IEmployeeOperations.h"
#include "Person.h"

class Employee : public IEmployeeOperations, public Person{
    protected:
        double bonus, salary;
    public:
        Employee(std::string fst, std::string lst, int id, int age, double salary = 0.0, double bonus = 0.0);
        double calculateSalary() const override;
        // setters
        void assignBonus(double amount);
        bool setSalary(double salary);
        // getters
        double getSalary() const;
        double getBonus() const;
        // Display
        void Display() const override;
};