CC := g++ 
LDFLAGS := -Wall
CPPFLAGS := -std=c++11
CXXFLAGS :=

SRC_DIR := ./src/
INC_DIR := ./inc/

BIN_DIR := ./bin/

SRC_FILES := $(wildcard $(SRC_DIR)*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)%.cpp,$(BIN_DIR)%.o,$(SRC_FILES))

app_default := Application
app ?= $(app_default)

LIBDIR = -L/usr/lib/
LIBRARIES = -lX11 -lglut -lGL -lGLU -lm

all: clean-all mkbin build

build: $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $(app) $^ $(LIBDIR) $(LIBRARIES)

$(BIN_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CPPFLAGS) $(CXXFLAGS) $(INC_DIR) -c -o $@ $(LIBDIR) $< $(LIBRARIES)

.PHONY: clean clean-all
clean:
	rm -rf $(BIN_DIR)

clean-all: clean
	rm -rf *~ $(SRC_DIR)*~ $(INC_DIR)*~
	rm -rf $(app) $(app_default)

mkbin:
	mkdir $(BIN_DIR)
