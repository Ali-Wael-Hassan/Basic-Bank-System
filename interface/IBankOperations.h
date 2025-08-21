#pragma once

class IBankOperations{
    public:
        virtual ~IBankOperations() = 0;
        virtual bool deposit(double amount) = 0;
        virtual bool withdraw(double amount) = 0;
};
IBankOperations::~IBankOperations() {}