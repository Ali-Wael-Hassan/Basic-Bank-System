#pragma once
#include "IPerson.h"

class Person : public IPerson{
    protected:
        std::string fst, lst;
        int id, age;

    public:
        Person(std::string fst, std::string lst, int id, int age);
        // setters
        bool setFirstName(const std::string& fst) override;
        bool setLastName(const std::string& lst) override;
        bool setId(int id) override;
        bool setAge(int id) override;
        // getters
        std::string getFirstName() const override;
        std::string getLastName() const override;
        int getId() const override;
        int getAge() const override;
};