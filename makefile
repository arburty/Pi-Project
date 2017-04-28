# Makefile - CS370- HW5

default:
	g++ -o driver -std=c++11 -Wall *.cc -lwiringPi

clean:
	rm driver
