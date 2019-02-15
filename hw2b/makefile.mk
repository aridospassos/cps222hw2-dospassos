#compiller for hw2b1.cc
hw2b1: hw2b1.o
	g++ hw2b1.o -o hw2b1


hw2b1.o: hw2b1.cc
	g++ -c hw2b1.cc