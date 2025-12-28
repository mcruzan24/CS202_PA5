game: player.o user.o opponent.o trap.o treasure.o board.o entity.o helpers.o main.o
	g++ -o game player.o user.o opponent.o trap.o treasure.o board.o entity.o helpers.o main.o

player.o: player.cpp player.h
	g++ -c player.cpp

user.o: user.h user.cpp
	g++ -c user.cpp

opponent.o: opponent.h opponent.cpp
	g++ -c opponent.cpp

trap.o: trap.h trap.cpp
	g++ -c trap.cpp

treasure.o: treasure.h treasure.cpp
	g++ -c treasure.cpp

board.o: board.h board.cpp
	g++ -c board.cpp

entity.o: entity.h entity.cpp
	g++ -c entity.cpp

helpers.o: helpers.h helpers.cpp
	g++ -c helpers.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o game