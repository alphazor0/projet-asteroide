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
SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/mobile.cpp $(SRC_DIR)/asteroide.cpp
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/mobile.o $(OBJ_DIR)/asteroide.o

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

# Clean up object files and the executable
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
