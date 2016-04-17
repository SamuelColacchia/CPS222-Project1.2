project1: board.o gameOfLife.o project1.o
	g++ -o $@ $^

gameOfLife.0: gameOfLife.h
board.o: board.h

%.0:	%.cc
	g++ -c $<
