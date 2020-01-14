CPP=g++ --std=c++11 

all : projet

projet : case.o   plateau.o joueur.o test.o monstre.o
	$(CPP) -o projet  plateau.o  case.o joueur.o test.o monstre.o
case.o : Case.cpp Case.hpp
	$(CPP) -c Case.cpp
plateau.o : Plateau.cpp Plateau.hpp Case.hpp
	$(CPP) -c Plateau.cpp
joueur.o : Joueur.cpp Joueur.hpp
	$(CPP) -c Joueur.cpp
monstre.o: Monstre.cpp Monstre.hpp
	$(CPP) -c Monstre.cpp
test.o : Test.cpp Plateau.hpp Joueur.hpp Monstre.hpp
	$(CPP) -c Test.cpp
clean :
	rm *.o 