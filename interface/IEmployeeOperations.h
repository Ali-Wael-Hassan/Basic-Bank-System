#pragma once

class IEmployeeOperations{
    public:
        virtual ~IEmployeeOperations() = 0;
        virtual double calculateSalary() const = 0;
        virtual void assignBonus(double amount) = 0;
};
IEmployeeOperations::~IEmployeeOperations() {}