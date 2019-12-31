CPP=g++ --std=c++11 

all : projet

projet : case.o   plateau.o joueur.o test.o
	$(CPP) -o projet  Plateau.o  Case.o Joueur.o Test.o
case.o : Case.cpp Case.hpp
	$(CPP) -c Case.cpp
plateau.o : Plateau.cpp Plateau.hpp Case.hpp
	$(CPP) -c Plateau.cpp
joueur.o : Joueur.cpp Joueur.hpp
	$(CPP) -c Joueur.cpp
test.o : Test.cpp Plateau.hpp Joueur.hpp
	$(CPP) -c Test.cpp
clean :
	rm *.o 