main: main.o imagehelpers.o funcs.o
	g++ -o main main.o imagehelpers.o funcs.o

main.o: main.cpp imagehelpers.cpp funcs.cpp

clean:
	rm -f main.o imagehelpers.o main funcs.o
