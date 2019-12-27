CPP=g++ --std=c++11 -Wall

all : projet

projet : case.o  test.o plateau.o
	$(CPP) -o projet  plateau.o test.o case.o
case.o : Case.cpp Case.hpp
	$(CPP) -c Case.cpp
plateau.o : Plateau.cpp Plateau.hpp Case.hpp
	$(CPP) -c Plateau.cpp

test.o : Test.cpp  Plateau.hpp
	$(CPP) -c Test.cpp
clean :
	rm *.o 