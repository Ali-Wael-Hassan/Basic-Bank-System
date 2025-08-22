#include "Bank.h"


Bank::Bank()
{
    std::string s = "Data.txt";
    try {
        Repository::load(s, this->DB);
    } catch (const std::exception& e) {
        std::cout << "Warning: Could not load data: " << e.what() << "\n";
    }
}

Bank::~Bank(){
    std::string s = "Data.txt";
    try {
        Repository::save(s, this->DB);
    } catch (const std::exception& e) {
        std::cerr << "Warning: Could not save data: " << e.what() << "\n";
    }
    for(auto& [key,person]:DB){
        delete person;
    }
}
// Base Menue Operations
bool Bank::signUp(const std::string &username, const std::string &password,const std::string &firstName, const std::string &lastName,int id, int age, double balance){
    return createAccount<CustomerAccount>(username, firstName, lastName, id, age, username, password, balance);
}

bool Bank::signUp(const std::string &username, const std::string &password,const std::string &firstName, const std::string &lastName,int id, int age, double salary, double bonus){
    return createAccount<Employee>(username, firstName, lastName, id, age, username, password, salary, bonus);
}

bool Bank::signIn(const std::string &username, const std::string &password){
    auto it = DB.find(username);
    if(it == DB.end()){
        std::cout << "Wrong Username.\n";
        return false;
    }
    
    auto customer = dynamic_cast<CustomerAccount*>(it->second);
    auto employee = dynamic_cast<Employee*>(it->second);
    if(customer){
        if (customer->getPassword() != password) {
            std::cout << "Incorrect password.\n";
            return false;
        }
    
        logged = customer;
        std::cout << "Sign in successful: " << username << '\n';
        return true;
    } else if(employee){
        if (employee->getPassword() != password) {
            std::cout << "Incorrect password.\n";
            return false;
        }
    
        logged = employee;
        std::cout << "Sign in successful: " << username << '\n';
        return true;
    } else{
        std::cout << "User isn't Entity.\n";
        return false;
    }
}

bool Bank::signOut(){
    if(!logged){
        std::cout << "You aren't logged into account.\n";
        return false;
    }
    logged = nullptr;
    std::cout << "Signed out successful!\n";
    return true;
}
// Customer Exclusive Operation
bool Bank::CustomerDeposit(double amount){
    if(!logged){
        std::cout << "You aren't logged into account.\n";
        return false;
    }
    IBankOperations* dep = dynamic_cast<IBankOperations*>(logged);
    if(!dep){
        std::cout << "Only customers can deposit!\n";
        return false;
    }
    if(!dep->deposit(amount)){
        std::cout << "Invalid amount!\n";
        return false;
    }
    std::cout << "Deposit " << amount << " successful\n";
    return true;
}

bool Bank::CustomerWithdraw(double amount){
    if(!logged){
        std::cout << "You aren't logged into account.\n";
        return false;
    }
    IBankOperations* with = dynamic_cast<IBankOperations*>(logged);
    if(!with){
        std::cout << "Only customers can withdraw!\n";
        return false;
    }
    if(!with->withdraw(amount)){
        if(amount < 0) std::cout << "Invalid amount!\n";
        else std::cout << "Too high amount!\n";
        return false;
    }
    std::cout << "Withdraw " << amount << " successful\n";
    return true;
}
// Employee Exclusive Operation
bool Bank::EmployeeBonus(double amount){
    if(!logged){
        std::cout << "You aren't logged into account.\n";
        return false;
    }
    IEmployeeOperations* bonus = dynamic_cast<IEmployeeOperations*>(logged);
    if(!bonus){
        std::cout << "Only Employee can have bonus!\n";
        return false;
    }
    bonus->assignBonus(amount);
    std::cout << "Bonus " << bonus->getBonus() << " successful\n";
    return true;
}

bool Bank::EmployeeSalary(double amount){
    if(!logged){
        std::cout << "You aren't logged into account.\n";
        return false;
    }
    IEmployeeOperations* salary = dynamic_cast<IEmployeeOperations*>(logged);
    if(!salary){
        std::cout << "Only Employee can have salary!\n";
        return false;
    }
    if(!salary->setSalary(amount)){
        std::cout << "Invalid amount!\n";
        return false;
    }
    std::cout << "Salary " << salary->getSalary() << " successful\n";
    return true;
}
// Intersection Operation
bool Bank::ChangePassword(const std::string &user, const std::string &Password, const std::string &newPassword){
    auto it = DB.find(user);
    if(it == DB.end()){
        std::cout << "Wrong Username.\n";
        return false;
    }
    IAccountManagment* pass = dynamic_cast<IAccountManagment*>(it->second);
    if(!pass){
        std::cout << "This User isn't Entity.\n";
        return false;
    }
    if(pass->getPassword() != Password){
        std::cout << "Wrong Password!\n";
        return false;
    }
    if(!pass->changePassword(newPassword)){
        std::cout << "Invalid New Password!\n";
        return false;
    }
    std::cout << "Changed Password successful!\n";
    return true;
}

bool Bank::ChangeUser(const std::string &user, const std::string &Password, const std::string &newUser){
    auto it = DB.find(user);
    if(it == DB.end()){
        std::cout << "Wrong Username.\n";
        return false;
    }
    IAccountManagment* pass = dynamic_cast<IAccountManagment*>(it->second);
    if(!pass){
        std::cout << "This User isn't Entity.\n";
        return false;
    }
    if(pass->getPassword() != Password){
        std::cout << "Wrong Password!\n";
        return false;
    }
    if(!pass->changeUser(newUser)){
        std::cout << "Invalid New User!\n";
        return false;
    }
    logged = nullptr;
    IPerson* ptr = it->second;
    DB.erase(it);
    DB[newUser] = ptr;
    logged = ptr;
    std::cout << "Changed User successful!\n";
    return true;
}
// Display
void Bank::Display(){
    if(!logged){
        std::cout << "You aren't logged into account.\n";
        return;
    }
    Screen::print(*logged);
}
// getter
IPerson* Bank::getLog(){
    return this->logged;
}