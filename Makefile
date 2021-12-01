SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -L./$(LIB)  -c

	
# ************  CREACION DEL EJECUTABLE  ***************

all: $(BIN)/usocolas_max

$(BIN)/usocolas_max: $(OBJ)/usocolas_max.o $(OBJ)/cola_max_pila.o  $(LIB)/libcolamax.a
	$(CXX) -L./$(LIB) -o $(BIN)/usocolas_max $(OBJ)/usocolas_max.o $(OBJ)/cola_max_pila.o -I$(INC) -lcolamax


# ************  CREACION DE OBJETOS  **************

$(OBJ)/usocolas_max.o: $(SRC)/usocolas_max.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/usocolas_max.o $(SRC)/usocolas_max.cpp	-lcolamax

$(OBJ)/cola_max_pila.o: $(SRC)/cola_max_pila.cpp #$(INC)/pila.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cola_max_pila.o $(SRC)/cola_max_pila.cpp -lcolamax

#$(OBJ)/pila.o: $(SRC)/pila.cpp
#	$(CXX) $(CPPFLAGS) -o $(OBJ)/pila.o $(SRC)/pila.cpp -lcolamax


# *************  CREACION DE BIBLIOTECAS  *********************

$(LIB)/libcolamax.a: $(OBJ)/usocolas_max.o $(OBJ)/cola_max_pila.o
	ar rvs $(LIB)/libcolamax.a $(OBJ)/usocolas_max.o $(OBJ)/cola_max_pila.o

# ************  Generación de documentación  ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(LIB)/*.a

mrproper : clean
	-rm $(BIN)/* doc/html/*
