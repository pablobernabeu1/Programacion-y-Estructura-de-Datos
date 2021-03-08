# Pablo Antonio Bernabeu Cartagena 20103111-V

main: main.o tcalendario.o
	g++ -o main main.o tcalendario.o

main.o: main.cpp tcalendario.h
	g++ -c main.cpp

tcalendario.o: tcalendario.h tcalendario.cpp
	g++ -c tcalendario.cpp



tad: tad.o tcalendario.o
	g++ -o tad tad10.o tcalendario.o

tad.o: tad10.cpp tcalendario.h
	g++ -c tad10.cpp

clean:
	rm main.o tcalendario.o main tad tad10.o

m:
	./main

t:
	./tad
