#pragma once
#include "Screen.h"
#include "CustomerAccount.h"
#include "Employee.h"
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iostream>

class Repository {
public:

    // Escape/unescape helper functions
    static std::string escape(const std::string& s);

    static std::string unescape(const std::string& s);

    // Save database to file
    static void save(const std::string& File, const std::map<std::string, IPerson*>& DB);

    // Load database from file
    static void load(const std::string& File, std::map<std::string, IPerson*>& DB);
};