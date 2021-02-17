# Pablo Antonio Bernabeu Cartagena 20083111-V

main: main.o TCalendario.o
	g++ -o main main.o TCalendario.o

main.o: main.cc TCalendario.h
	g++ -c main.cc
	
TCalendario.o: TCalendario.h TCalendario.cc
	g++ -c TCalendario.cc
	
clean: 
	rm main.o TCalendario.o main
 
 
 
