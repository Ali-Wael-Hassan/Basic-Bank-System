#include "Repository.h"

std::string Repository::escape(const std::string& s) {
    std::string res;
    for (char c : s) {
        if (c == '|') res += "\\|";
        else if (c == '\\') res += "\\\\";
        else res += c;
    }
    return res;
}

std::string Repository::unescape(const std::string& s) {
    std::string res;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '\\' && i + 1 < s.size()) {
            if (s[i + 1] == '|') { res += '|'; i++; }
            else if (s[i + 1] == '\\') { res += '\\'; i++; }
            else res += '\\';
        } else res += s[i];
    }
    return res;
}

// Save database to file
void Repository::save(const std::string& File, const std::map<std::string, IPerson*>& DB) {
    std::ofstream out(File);
    if (!out) throw std::runtime_error("Cannot open file: " + File);

    for (const auto& [key, person] : DB) {
        out << escape(key) << '|'
            << escape(person->getFirstName()) << '|'
            << escape(person->getLastName()) << '|'
            << person->getId() << '|'
            << person->getAge() << '|';

        if (auto c = dynamic_cast<CustomerAccount*>(person)) {
            out << "Customer|"
                << escape(c->getUser()) << '|'
                << escape(c->getPassword()) << '|'
                << c->getBalance();
        } else if (auto e = dynamic_cast<Employee*>(person)) {
            out << "Employee|"
                << e->getSalary() << '|'
                << e->getBonus();
        }
        out << '\n';
    }
}

// Load database from file
void Repository::load(const std::string& File, std::map<std::string, IPerson*>& DB) {
    std::ifstream in(File);
    if (!in) throw std::runtime_error("Cannot open file: " + File);

    // Free old objects
    for (auto& [k, v] : DB) delete v;
    DB.clear();

    std::string line;
    int no = 0;
    while (std::getline(in, line)) {
        ++no;
        if (line.empty()) continue;
        try {
            std::stringstream ss(line);
            std::string key, firstName, lastName, type, user, pass, temp;
            int id = 0, age = 0;
            double balance = 0.0, salary = 0.0, bonus = 0.0;

            std::getline(ss, key, '|'); key = unescape(key);
            std::getline(ss, firstName, '|'); firstName = unescape(firstName);
            std::getline(ss, lastName, '|'); lastName = unescape(lastName);

            std::getline(ss, temp, '|'); id = std::stoi(temp);
            std::getline(ss, temp, '|'); age = std::stoi(temp);

            std::getline(ss, type, '|');

            if (type == "Customer") {
                std::getline(ss, user, '|'); user = unescape(user);
                std::getline(ss, pass, '|'); pass = unescape(pass);
                std::getline(ss, temp); balance = std::stod(temp);

                IPerson* person = new CustomerAccount(firstName, lastName, id, age, user, pass, balance);
                DB[key] = person;

            } else if (type == "Employee") {
                std::getline(ss, temp, '|'); salary = std::stod(temp);
                std::getline(ss, temp); bonus = std::stod(temp);

                IPerson* person = new Employee(firstName, lastName, id, age, user, pass, salary, bonus);
                DB[key] = person;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Warning: Skipping invalid line: " << no << " (" << e.what() << ")\n";
            continue;
        }
    }
}