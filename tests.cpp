/** 
* Spring 2023 - Lab 11
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Profile class")
{
    Profile p1("marco", "Marco");  
    Profile p2("tarma1", "Tarma Roving");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");
    p1.setDisplayName("Marco Rossi"); 
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");

}

TEST_CASE("Network class")
{
    //Task B
    Network nw;
    CHECK(nw.addUser("mario", "Mario") == true);  
    CHECK(nw.addUser("luigi", "Luigi") == true);    

    CHECK(nw.addUser("mario", "Mario2") == false);    
    CHECK(nw.addUser("mario 2", "Mario2") == false);  
    CHECK(nw.addUser("mario-2", "Mario2") == false);  

    for(int i = 2; i < 20; i++)
    {
        CHECK(nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)) == true);
    }
    CHECK(nw.addUser("yoshi", "Yoshi") == false);


    Network nw2;

    CHECK(nw2.addUser("mario", "Mario") == true);
    CHECK(nw2.addUser("luigi", "Luigi") == true);
    CHECK(nw2.addUser("yoshi", "Yoshi") == true);
    
    //Task C
    CHECK(nw2.follow("mario", "luigi") == true);
    CHECK(nw2.follow("mario", "yoshi") == true);
    CHECK(nw2.follow("luigi", "mario") == true);
    CHECK(nw2.follow("luigi", "yoshi") == true);
    CHECK(nw2.follow("yoshi", "mario") == true);
    CHECK(nw2.follow("yoshi", "luigi") == true);

    CHECK(nw2.follow("luigi", "penpen") == false);
    CHECK(nw2.follow("subaru", "moistmeter") == false);
    CHECK(nw2.follow("Gigguk", "luigi") == false);

    CHECK(nw2.getFollowing(0,0) == false);
    CHECK(nw2.getFollowing(0,1) == true);
    CHECK(nw2.getFollowing(0,2) == true);
    CHECK(nw2.getFollowing(1,0) == true);
    CHECK(nw2.getFollowing(1,1) == false);
    CHECK(nw2.getFollowing(1,2) == true);
    CHECK(nw2.getFollowing(2,0) == true);
    CHECK(nw2.getFollowing(2,1) == true);
    CHECK(nw2.getFollowing(2,2) == false);
}