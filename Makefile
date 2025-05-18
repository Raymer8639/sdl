run:main.o
	g++ main.o -o run -lSDL3
	rm main.o
	mv run bin
main.o:src/main.cc
	g++ src/main.cc -c -o main.o
