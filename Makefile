main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o -std=c++17

tests: tests.o profile.o network.o
	g++ -o tests tests.o profile.o network.o -std=c++17



main.o: main.cpp profile.cpp network.cpp profile.h network.h

tests.o: tests.cpp profile.cpp network.cpp doctest.h profile.h network.h

profile.o: profile.cpp profile.h

network.o: network.cpp network.h

clean:
	rm -f main.o funcs.o tests.o profile.o network.o