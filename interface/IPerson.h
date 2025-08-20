#pragma once
#include <string>

class IPerson{
    public:
        virtual ~IPerson() = 0;
        // setters
        virtual bool setFirstName(const std::string& fst) = 0;
        virtual bool setLastName(const std::string& lst) = 0;
        virtual bool setId(int id) = 0;
        virtual bool setAge(int id) = 0;
        // getters
        virtual std::string getFirstName() const = 0;
        virtual std::string getLastName() const = 0;
        virtual int getId() const = 0;
        virtual int getAge() const = 0;
};
inline IPerson::~IPerson() {}