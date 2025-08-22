#pragma once
#include "Bank.h"

class InterActive{
    private:
        Bank bank;
        void loginCustomerMenu();
        void customerMenu();
        void loginEmployeeMenu();
        void employeeMenu();
    public:
        void run();
};