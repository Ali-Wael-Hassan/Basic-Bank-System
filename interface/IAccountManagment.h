#pragma once
#include <string>

class IAccountManagment{
    public:
        virtual ~IAccountManagment() = 0;
        virtual bool changePassword(const std::string& newPassword) = 0;
        virtual bool changeUser(const std::string& newUser) = 0;
        virtual std::string getPassword() const = 0;
        virtual std::string getUser() const = 0;
};
inline IAccountManagment::~IAccountManagment(){}