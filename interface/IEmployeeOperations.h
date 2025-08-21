#pragma once

class IEmployeeOperations{
    public:
        virtual ~IEmployeeOperations() = 0;
        virtual double calculateSalary() const = 0;
        virtual void assignBonus(double amount) = 0;
        virtual bool setSalary(double salary) = 0;
        virtual double getSalary() const = 0;
        virtual double getBonus() const = 0;
};
inline IEmployeeOperations::~IEmployeeOperations() {}