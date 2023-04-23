/** 
* Spring 2023 - Lab 11
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#include <iostream>
#include <string>
#include "profile.h"
#include "network.h"

int main()
{
    Profile profile1("Metails", "SuperIdol's Smile");
    std::cout << profile1.getFullName() << "\n";

    Network nw;
    std::cout << nw.addUser("mario", "Mario") << std::endl;

    Network nw2;

    nw2.addUser("mario", "Mario");
    nw2.addUser("luigi", "Luigi");
    nw2.addUser("yoshi", "Yoshi");

    nw2.follow("mario", "luigi");
    nw2.follow("mario", "yoshi");
    nw2.follow("luigi", "mario");
    nw2.follow("luigi", "yoshi");
    nw2.follow("yoshi", "mario");
    nw2.follow("yoshi", "luigi");

    nw2.addUser("wario", "Wario");
    
    for(int i = 2; i < 6; i++) 
    {
        std::string usrn = "mario" + std::to_string(i);
        std::string dspn = "Mario " + std::to_string(i);
        nw2.addUser(usrn, dspn);
        nw2.follow(usrn, "mario");
    }

    nw2.follow("mario2", "luigi");

    nw2.printDot();

    return 0;
}