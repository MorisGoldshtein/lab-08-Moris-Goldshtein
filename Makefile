main: main.o imagehelpers.o funcs.o
	g++ -o main main.o imagehelpers.o funcs.o

main.o: main.cpp imagehelpers.cpp funcs.cpp

clean:
	rm -f main.o imagehelpers.o main funcs.o taska.pgm taskb.pgm taskc.pgm taskd.pgm taske.pgm taskf.pgm outImage.pgm
