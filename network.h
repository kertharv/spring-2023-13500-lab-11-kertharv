#pragma once
#include "profile.h"
#include <string>

class Network 
{
private:
  static const int MAX_USERS = 20;
  bool following[MAX_USERS][MAX_USERS]; 
  int numUsers;            
  Profile profiles[MAX_USERS];     

  int findID (std::string usrn)
  {
    for(int i = 0; i < MAX_USERS; i++)
    {
        if(profiles[i].getUsername() == usrn)
        {
            return i;
        }
    }
    return -1;
}
public:

  Network();
  bool addUser(std::string usrn, std::string dspn);
  bool follow(std::string usrn1, std::string usrn2);
  void printDot();
  bool getFollowing(int row, int col) const;
};