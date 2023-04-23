/** 
* Spring 2023 - Lab 11
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#include "profile.h"
#include <string>

Profile::Profile(std::string usrn, std::string dspn)
{
    username = usrn;
    displayname = dspn;
}

Profile::Profile()
{
    username = "";
    displayname = "";
}

std::string Profile::getUsername() const
{
    return username;
}

std::string Profile::getFullName() const
{
    return displayname + " " + "(@" + username + ")";
}

void Profile::setDisplayName(std::string dspn)
{
    displayname = dspn;
}