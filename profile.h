#pragma once
#include <string>
class Profile 
{
private:
    std::string username;
    std::string displayname;
public:
    Profile(std::string usrn, std::string dspn);
    Profile();
    std::string getUsername() const;
    std::string getFullName() const;
    void setDisplayName(std::string dspn);
};