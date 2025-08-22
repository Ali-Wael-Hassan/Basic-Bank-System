#include "FullNameFormatter.h"

std::string FullNameFormatter::fullName(const std::string& fst,const std::string& lst){
    std::string f = fst, l = lst;
    for(auto& c : f) c = std::tolower(c);
    for(auto& c : l) c = tolower(c);
    f[0] = toupper(f[0]);
    l[0] = toupper(l[0]);
    return f + " " + l;
}