project1: gameOfLife.o project1.o
	g++ -o $@ $^

gameOfLife.0: gameOfLife.h

%.0:	%.cc
	g++ -c $<
