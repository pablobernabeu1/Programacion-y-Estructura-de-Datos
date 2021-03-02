# Pablo Antonio Bernabeu Cartagena 20083111-V

main: main.o tcalendario.o
	g++ -o main main.o tcalendario.o

main.o: main.cpp tcalendario.h
	g++ -c main.cpp

tcalendario.o: tcalendario.h tcalendario.cpp
	g++ -c tcalendario.cpp



tad: tad.o tcalendario.o
	g++ -o tad tad04.o tcalendario.o

tad.o: tad04.cpp tcalendario.h
	g++ -c tad04.cpp

clean:
	rm main.o tcalendario.o main tad tad04.o

m:
	./main

t:
	./tad
