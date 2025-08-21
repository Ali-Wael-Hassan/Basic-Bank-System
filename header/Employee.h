#pragma once
#include "IEmployeeOperations.h"
#include "IAccountManagment.h"
#include "Person.h"

class Employee : public Person, public IEmployeeOperations, public IAccountManagment{
    protected:
        std::string user, password;
        double bonus, salary;
    public:
        Employee(std::string fst, std::string lst, int id, int age, std::string user, std::string password, double salary = 0.0, double bonus = 0.0);
        ~Employee() {};
        double calculateSalary() const override;
        bool changePassword(const std::string& newPassword) override;
        bool changeUser(const std::string& newUser) override;
        // setters
        void assignBonus(double amount);
        bool setSalary(double salary) override;
        // getters
        double getSalary() const override;
        double getBonus() const override;
        std::string getPassword() const override;
        std::string getUser() const override;
        // Display
        void Display() const override;
};