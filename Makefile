SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

	
# ************ Compilación de módulos ************
$(BIN)/usocolas_max: $(OBJ)/usocolas_max.o $(OBJ)/cola_max_pila.o $(OBJ)/pila.o 
	$(CXX) -o $(BIN)/usocolas_max $(OBJ)/usocolas_max.o -I$(INC)

$(OBJ)/usocolas_max.o: $(SRC)/usocolas_max.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/usocolas_max.o $(SRC)/usocolas_max.cpp -I$(INC)	

$(OBJ)/cola_max_pila.o: $(SRC)/cola_max_pila.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cola_max_pila.o $(INC)/cola_max_pila.h

$(OBJ)/pila.o: $(SRC)/pila.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/pila.o $(INC)/pila.h

all: $(BIN)/pruebacola_max
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
