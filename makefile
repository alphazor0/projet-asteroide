# Compiler and flags
CXX = g++
CXXFLAGS = -c -Wfatal-errors -Iheaders
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRC_DIR = src
HEADERS_DIR = headers
OBJ_DIR = obj

# Target executable
TARGET = sfml-app

# Source files and object files
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/mobile.cpp $(SRC_DIR)/asteroide.cpp $(SRC_DIR)/jeu.cpp $(SRC_DIR)/projectile.cpp $(SRC_DIR)/vague.cpp $(SRC_DIR)/vaisseau.cpp
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/mobile.o $(OBJ_DIR)/asteroide.o $(OBJ_DIR)/jeu.o $(OBJ_DIR)/projectile.o $(OBJ_DIR)/vague.o $(OBJ_DIR)/vaisseau.o

# Default target
all: $(TARGET)

# Link objects to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	./$(TARGET)

# Compile main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

# Compile mobile.o
$(OBJ_DIR)/mobile.o: $(SRC_DIR)/mobile.cpp $(HEADERS_DIR)/mobile.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/mobile.cpp -o $(OBJ_DIR)/mobile.o

# Compile asteroide.o
$(OBJ_DIR)/asteroide.o: $(SRC_DIR)/asteroide.cpp $(HEADERS_DIR)/asteroide.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/asteroide.cpp -o $(OBJ_DIR)/asteroide.o

# Compile jeu.o
$(OBJ_DIR)/jeu.o: $(SRC_DIR)/jeu.cpp $(HEADERS_DIR)/jeu.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/jeu.cpp -o $(OBJ_DIR)/jeu.o

# Compile projectile.o
$(OBJ_DIR)/projectile.o: $(SRC_DIR)/projectile.cpp $(HEADERS_DIR)/projectile.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/projectile.cpp -o $(OBJ_DIR)/projectile.o

# Compile vague.o
$(OBJ_DIR)/vague.o: $(SRC_DIR)/vague.cpp $(HEADERS_DIR)/vague.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/vague.cpp -o $(OBJ_DIR)/vague.o

# Compile vaisseau.o
$(OBJ_DIR)/vaisseau.o: $(SRC_DIR)/vaisseau.cpp $(HEADERS_DIR)/vaisseau.h
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/vaisseau.cpp -o $(OBJ_DIR)/vaisseau.o	


# Clean up object files and the executable
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
