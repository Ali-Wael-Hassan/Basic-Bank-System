#include "Bank.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()

int getIntInputSafe(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Enter a number.\n";
            continue;
        }
        return value;
    }
}

double getDoubleInputSafe(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Enter a number.\n";
            continue;
        }
        return value;
    }
}

int main() {
    std::srand(std::time(nullptr));
    Bank bank;

    std::vector<std::string> usernames = {"johndoe", "janedoe", "bobwilson", "managerone", "managertwo"};

    std::cout << "=== BANKING SYSTEM FULL STRESS TEST ===\n\n";

    // 1. Customer Signups
    std::cout << "1. Testing Customer Signups...\n";
    for(int i = 0; i < 3; ++i) {
        double balance = 1000.0 + rand()%5000;
        bool ok = bank.signUp(usernames[i], "pass123", "First"+std::to_string(i), "Last"+std::to_string(i),
                              1000+i, 20+i, balance);
        std::cout << (ok ? "Sign up successful!\n" : "Sign up failed!\n");
    }

    // 1a. Invalid Customer Signups
    std::cout << "1a. Testing invalid Customer Signups...\n";
    bank.signUp("johndoe", "", "", "", 0, -1, -100);  // duplicate username, invalid fields
    bank.signUp("newuser", "", "", "", 0, 0, 0);       // invalid names/balance

    // 2. Employee Signups
    std::cout << "\n2. Testing Employee Signups...\n";
    for(int i = 3; i < 5; ++i) {
        double salary = 50000 + rand()%10000;
        double bonus = 5000 + rand()%5000;
        bool ok = bank.signUp(usernames[i], "emp123", "Manager"+std::to_string(i), "Last"+std::to_string(i),
                              2000+i, 30+i, salary, bonus);
        std::cout << (ok ? "Sign up successful!\n" : "Sign up failed!\n");
    }

    // 2a. Invalid Employee Signups
    std::cout << "2a. Testing invalid Employee Signups...\n";
    bank.signUp("managerone", "emp123", "", "", 0, -1, -1000, -500);  // duplicate + invalid fields
    bank.signUp("newmanager", "emp123", "", "", 0, 0, 0, 0);          // invalid fields

    // 3. Duplicate username prevention
    std::cout << "\n3. Testing Duplicate Username Prevention...\n";
    bank.signUp("johndoe", "pass123", "John", "Doe", 1010, 25, 2000.0);

    // 4. Customer operations
    std::cout << "\n4. Testing Customer Operations...\n";
    if(bank.signIn("johndoe", "pass123")) {
        bank.CustomerDeposit(500);
        bank.CustomerDeposit(0);      // invalid
        bank.CustomerDeposit(-100);   // invalid

        bank.CustomerWithdraw(300);
        bank.CustomerWithdraw(0);     // invalid
        bank.CustomerWithdraw(-50);   // invalid
        bank.CustomerWithdraw(99999); // more than balance

        bank.signOut();
    }

    // 5. Employee operations
    std::cout << "\n5. Testing Employee Operations...\n";
    if(bank.signIn("managerone", "emp123")) {
        bank.EmployeeSalary(60000);
        bank.EmployeeSalary(-1000);  // invalid
        bank.EmployeeBonus(7000);
        bank.EmployeeBonus(-500);    // invalid

        bank.signOut();
    }

    // 6. Operations without login
    std::cout << "\n6. Operations Without Login...\n";
    bank.CustomerDeposit(100);
    bank.CustomerWithdraw(50);
    bank.EmployeeSalary(50000);
    bank.EmployeeBonus(5000);

    // 7. Account management
    std::cout << "\n7. Testing Account Management...\n";
    bank.ChangePassword("johndoe", "wrongpass", "newpass"); // wrong current password
    bank.ChangePassword("johndoe", "pass123", "");         // empty new password
    bank.ChangeUser("janedoe", "wrongpass", "janenew");    // wrong current password
    bank.ChangeUser("janedoe", "pass123", "johndoe");      // duplicate username
    bank.ChangeUser("janedoe", "pass123", "");             // empty new username

    // 8. Sign in/out edge cases
    std::cout << "\n8. Sign In/Out Edge Cases...\n";
    bank.signOut();                    // signing out when no one logged in
    bank.signIn("nonexistent", "pass");
    bank.signIn("johndoe", "wrongpass");
    bank.signIn("johndoe", "pass123"); // valid
    bank.signIn("managerone", "emp123"); // trying to login while another logged in
    bank.signOut();

    // 9. Mass random account stress test
    std::cout << "\n9. Mass Account Creation Stress Test...\n";
    for(int i = 0; i < 20; ++i){
        std::string uname = "testuser" + std::to_string(i);
        double balance = rand()%10000;
        bank.signUp(uname, "abc123", "User"+std::to_string(i), "Test"+std::to_string(i),
                    3000+i, 18+i, balance);
    }

    std::cout << "\n=== FULL STRESS TEST COMPLETED ===\n";
    return 0;
}
