/** 
* Spring 2023 - Lab 11
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#include <iostream>
#include "network.h"

Network::Network()
{

    numUsers = 0;

    for(int i = 0; i < MAX_USERS; i++)
    {
        for(int j = 0; j < MAX_USERS; j++)
        {
            following[i][j] = false;
        }
    }
}

bool Network::addUser(std::string usrn, std::string dspn)
{
    bool alphabetical = true;
    for(int i = 0; i < usrn.length(); i++)
    {
        if(!isalpha(usrn[i]) && !isdigit(usrn[i]))
        {
            alphabetical = false;
        }
    }

    if(numUsers < MAX_USERS && alphabetical && findID(usrn) == -1)
    {
        profiles[numUsers] = Profile(usrn, dspn);
        numUsers++;
        return true;
    }
    return false;

}

bool Network::follow(std::string usrn1, std::string usrn2)
{

    if(findID(usrn1) != -1 && findID(usrn2) != -1)
    {
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }else{
        return false;
    }
}

void Network::printDot()
{
    std::string connectionString;
    std::string usrnstring;
    bool firstTrue = true;
    for(int row = 0; row < MAX_USERS; row++)
    {
        for(int col = 0; col < MAX_USERS; col++)
        {
            if(following[row][col] == true)
            {
                connectionString += "\t\"@" + profiles[row].getUsername() + "\" -> \"@" + profiles[col].getUsername() + "\"\n";
                if(firstTrue){
                    usrnstring += "\t\"@" + profiles[row].getUsername() + "\"\n";
                    firstTrue = false;
                }
            }
        }
        firstTrue = true;
    }
    std::string finalString = "digraph {\n" + usrnstring + "\n" + connectionString + "}\n";
    std::cout << finalString;
}

bool Network::getFollowing(int row, int col) const
{
    return following[row][col];
}