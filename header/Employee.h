#pragma once
#include "IEmployeeOperations.h"
#include "Person.h"

class Employee : public IEmployeeOperations, public IAccountManagment, public Person{
    protected:
        std::string user, password;
        double bonus, salary;
    public:
        Employee(std::string fst, std::string lst, int id, int age, std::string user, std::string password, double salary = 0.0, double bonus = 0.0);
        double calculateSalary() const override;
        bool changePassword(const std::string& newPassword) override;
        bool changeUser(const std::string& newUser) override;
        // setters
        void assignBonus(double amount);
        bool setSalary(double salary) override;
        // getters
        double getSalary() const override;
        double getBonus() const override;
        std::string getPassword() override;
        std::string getUser() override;
        // Display
        void Display() const override;
};