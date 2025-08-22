#include "InterActive.h"
#include <limits>
#include <algorithm>

void InterActive::loginCustomerMenu(){
    int choice = 0;
    std::string user, pass, fst, lst;
    int id, age;
    do {
        system("pause");
        std::cout << "\n=== Login ===\n";
        std::cout << "1. Sign in\n2. Register\n3. Exit\nChoice: ";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice! Please enter a number.\n";
            choice = 0;
            continue;
        }
        switch (choice) {
            case 1:
                std::cout << "\n=== Login ===\n";
                std::cout << "Username: "; std::cin >> user;
                std::cout << "Password: "; std::cin >> pass;
                if(bank.signIn(user,pass)) {
                    if(dynamic_cast<CustomerAccount*>(bank.getLog())) customerMenu();
                    else{
                        std::cout << "You aren't allowed to go into Employee accounts\n";
                        bank.signOut();
                    }
                }
                break;

            case 2:
                std::cout << "\n=== Register ===\n";
                std::cout << "Username: "; std::cin >> user;
                std::cout << "Password: "; std::cin >> pass;
                std::cout << "First Name: "; std::cin >> fst;
                std::cout << "Last Name: "; std::cin >> lst;
                std::cout << "ID: "; std::cin >> id;
                std::cout << "Age: "; std::cin >> age;
                if(bank.signUp(user,pass,fst,lst,id,age,0.0)){
                    if (bank.signIn(user, pass)) {
                        customerMenu();
                    }
                }
                break;

            case 3:
                std::cout << "Goodbye!\n";
                break;
            
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 3);
}

void InterActive::customerMenu(){
    int choice = 0;
    std::string user, pass, newpass, verifypass, newuser, verifyuser;
    double amount;
    do {
        system("pause");
        std::cout << "\n=== Customer Menu ===\n";
        std::cout << "1. Show info\n2. Change Password\n3. Change Username\n4. Deposit\n5. withdraw\n6. Sign out\nChoice: ";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice! Please enter a number.\n";
            choice = 0;
            continue;
        }
        switch (choice) {
            case 1:
                std::cout << "\n=== Info ===\n";
                bank.Display();
                break;

            case 2:
                std::cout << "\n=== Verification ===\n";
                std::cout << "Current Username: "; std::cin >> user;
                std::cout << "Current Password: "; std::cin >> pass;
                std::cout << "New Password: "; std::cin >> newpass;
                std::cout << "Verify New Password: "; std::cin >> verifypass;
                if(newpass != verifypass) std::cout << "New Password and Verify New Password are different\n";
                else{
                    if(bank.ChangePassword(user,pass,newpass)) {std::cout << "You Will be signed out\n"; choice = 6;}
                }
                break;

            case 3:
                std::cout << "\n=== Verification ===\n";
                std::cout << "Current Username: "; std::cin >> user;
                std::cout << "Current Password: "; std::cin >> pass;
                std::cout << "New Username: "; std::cin >> newuser;
                std::cout << "Verify New Username: "; std::cin >> verifyuser;
                if(newuser != verifyuser) std::cout << "New Username and Verify New Username are different\n";
                else{
                    if(bank.ChangeUser(user,pass,newuser)) {std::cout << "You Will be signed out\n"; choice = 6;}
                }
                break;

            case 4:
                std::cout << "\n=== Deposit ===\n";
                std::cout << "Enter the amount to deposit: "; std::cin >> amount;
                bank.CustomerDeposit(amount);
                break;

            case 5:
                std::cout << "\n=== Withdraw ===\n";
                std::cout << "Enter the amount to withdraw: "; std::cin >> amount;
                bank.CustomerWithdraw(amount);
                break;

            case 6:
                bank.signOut();
                break;

            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

void InterActive::loginEmployeeMenu(){
    int choice = 0;
    std::string user, pass, fst, lst;
    int id, age;
    double salary;
    do {
        system("pause");
        std::cout << "\n=== Login ===\n";
        std::cout << "1. Sign in\n2. Register\n3. Exit\nChoice: ";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice! Please enter a number.\n";
            choice = 0;
            continue;
        }
        switch (choice) {
            case 1:
                std::cout << "\n=== Login ===\n";
                std::cout << "Username: "; std::cin >> user;
                std::cout << "Password: "; std::cin >> pass;
                if(bank.signIn(user,pass)) {
                    if(dynamic_cast<Employee*>(bank.getLog())) employeeMenu();
                    else{
                        std::cout << "You aren't allowed to go into Customer accounts\n";
                        bank.signOut();
                    }
                }
                break;

            case 2:
                std::cout << "\n=== Register ===\n";
                std::cout << "Username: "; std::cin >> user;
                std::cout << "Password: "; std::cin >> pass;
                std::cout << "First Name: "; std::cin >> fst;
                std::cout << "Last Name: "; std::cin >> lst;
                std::cout << "ID: "; std::cin >> id;
                std::cout << "Age: "; std::cin >> age;
                std::cout << "Salary: "; std::cin >> salary;
                if(bank.signUp(user,pass,fst,lst,id,age,salary,0.0)){
                    if (bank.signIn(user, pass)) {
                        employeeMenu();
                        }
                    }
                break;

            case 3:
                std::cout << "Goodbye!\n";
                break;
            
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 3);
}

void InterActive::employeeMenu(){
    int choice = 0;
    std::string user, pass, newpass, verifypass, newuser, verifyuser;
    do {
        system("pause");
        std::cout << "\n=== Employee Menu ===\n";
        std::cout << "1. Show info\n2. Change Password\n3. Change Username\n4. Sign out\nChoice: ";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice! Please enter a number.\n";
            choice = 0;
            continue;
        }
        switch (choice) {
            case 1:
                std::cout << "\n=== Info ===\n";
                bank.Display();
                break;

            case 2:
                std::cout << "\n=== Verification ===\n";
                std::cout << "Current Username: "; std::cin >> user;
                std::cout << "Current Password: "; std::cin >> pass;
                std::cout << "New Password: "; std::cin >> newpass;
                std::cout << "Verify New Password: "; std::cin >> verifypass;
                if(newpass != verifypass) std::cout << "New Password and Verify New Password are different\n";
                else{
                    if(bank.ChangePassword(user,pass,newpass)) {std::cout << "You Will be signed out\n"; choice = 4;}
                }
                break;

            case 3:
                std::cout << "\n=== Verification ===\n";
                std::cout << "Current Username: "; std::cin >> user;
                std::cout << "Current Password: "; std::cin >> pass;
                std::cout << "New Username: "; std::cin >> newuser;
                std::cout << "Verify New Username: "; std::cin >> verifyuser;
                if(newuser != verifyuser) std::cout << "New Username and Verify New Username are different\n";
                else{
                    if(bank.ChangeUser(user,pass,newuser)) {std::cout << "You Will be signed out\n"; choice = 4;}
                }
                break;

            case 4:
                bank.signOut();
                break;

            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 4);
}

void InterActive::run() {
    int choice = 0;
    do {
        system("pause");
        std::cout << "\n=== Welcome to the Bank System ===\n";
        std::cout << "1. Customer Login/Register\n";
        std::cout << "2. Employee Login/Register\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice! Please enter a number.\n";
            choice = 0;
            continue;
        }
        switch (choice) {
            case 1:
                loginCustomerMenu();
                break;
            case 2:
                loginEmployeeMenu();
                break;
            case 3:
                std::cout << "Thank you for using the system. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);
}