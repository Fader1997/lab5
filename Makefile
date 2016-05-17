HugeInt:HugeInt.o lab5.o
	g++ -o HugeInt lab5.o HugeInt.o

HugeInt.o:HugeInt.cpp HugeInt.h
	g++ -c HugeInt.cpp

lab5.o:lab5.cpp HugeInt.h
	g++ -c lab5.cpp

clean:
	rm HugeInt *.o
