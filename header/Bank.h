#pragma once
#include "CustomerAccount.h"
#include "Employee.h"
#include "Screen.h"
#include "Repository.h"
#include <map>

class Bank{
    protected:
        std::map<std::string, IPerson*> DB;
        IPerson* logged = nullptr;
    public:
        Bank();
        ~Bank();
        // Base Menue Operations
        template <class T, typename... Args>
        bool createAccount(const std::string &username, Args &&...args){
            if(DB.find(username) != DB.end()){
                std::cout << "Username Already Exist!\n";
                return false;
            }
            try{
                DB[username] = new T(std::forward<Args>(args)...);
                std::cout << "Sign up successful!\n";
            }
            catch (const std::exception& e) {
                std::cout << "Sign up failed: " << e.what() << "\n";
                return false;
            } 
            catch (...) {
                std::cout << "Sign up failed: unknown error\n";
                return false;
            }
            return true;
        }
        bool signUp(const std::string& username, const std::string& password,
                const std::string& firstName, const std::string& lastName,
                int id, int age, double balance);
        bool signUp(const std::string& username, const std::string& password,
                const std::string& firstName, const std::string& lastName,
                int id, int age, double salary, double bonus);
        bool signIn(const std::string& username, const std::string& password);
        bool signOut();
        // Customer Exclusive Operation
        bool CustomerDeposit(double amount);
        bool CustomerWithdraw(double amount);
        // Employee Exclusive Operation
        bool EmployeeBonus(double amount);
        bool EmployeeSalary(double amount);
        // Intersection Operation
        bool ChangePassword(const std::string& user, const std::string& Password, const std::string& newPassword);
        bool ChangeUser(const std::string& user, const std::string& Password, const std::string& newUser);
        // Display
        void Display();
};