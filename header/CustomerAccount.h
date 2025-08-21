#pragma once
#include "IBankOperations.h"
#include "IAccountManagment.h"
#include "Person.h"

class CustomerAccount : public IBankOperations, public IAccountManagment, public Person{
    protected:
        std::string user, password;
        double balance;
    public:
        CustomerAccount(std::string fst, std::string lst, int id, int age, const std::string& user, const std::string& password, double balance = 0.0);
        bool deposit(double amount) override;
        bool withdraw(double amount) override;
        bool changePassword(const std::string& newPassword) override;
        bool changeUser(const std::string& newUser) override;
        void Display() const override;
};