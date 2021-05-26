CC=g++
OPTIONS= -g -w
DEBUG= #-D DEBUG
LIBDIR=lib
INCLUDEDIR=include
_OBJ= tcalendario.o tvectorcalendario.o tlistacalendario.o tabbcalendario.o tavlcalendario.o
OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

main:    src/main.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) src/main.cpp $(OBJ) -o main

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

tar:
	tar cvzf practica.tar.gz include lib src nombres.txt

clean:
	rm -f $(OBJ)