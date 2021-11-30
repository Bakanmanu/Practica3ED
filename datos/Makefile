SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

	
# ************ Compilación de módulos ************
$(BIN)/usocolas_max: $(OBJ)/usocolas_max.o $(OBJ)/Cola_max_Pila.o $(OBJ)/Pila.o 
	$(CXX) -o $(BIN)/usocolas_max $(OBJ)/usocolas_max.o -I$(INC)

$(OBJ)/usocolas_max.o: $(SRC)/usocolas_max.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)/usocolas_max.o $(SRC)/usocolas_max.cpp -I$(INC)	

$(OBJ)/Cola_max_Pila.o: $(SRC)/Cola_max_Pila.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)Cola_max_Pila.o $(INC)/Cola_max_Pila.h

$(OBJ)/Pila.o: $(SRC)/Pila.cpp
	$(CXX) $(CPPFLAGS) -o $(OBJ)Pila.o $(INC)/Pila.h

all: $(BIN)/pruebacola_max
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
