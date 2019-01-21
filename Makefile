CC := g++ 
LDFLAGS := -Wall
CPPFLAGS := -std=c++11
CXXFLAGS :=

#directories for where your source files are
SRC_DIR := ./src/
INC_DIR := ./inc/

#Where you want your files built 
BIN_DIR := ./bin/

#don't touch these.
SRC_FILES := $(wildcard $(SRC_DIR)*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)%.cc,$(BIN_DIR)%.o,$(SRC_FILES))

#name of the executable
app_default := Application
app ?= $(app_default)

#Open GL libraries.
LIBDIR = -L/usr/lib/
LIBRARIES = -lX11 -lglut -lGL -lGLU -lm

all: clean-all mkbin build

build: $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $(app) $^ $(LIBDIR) $(LIBRARIES)

$(BIN_DIR)%.o: $(SRC_DIR)%.cc
	$(CC) $(CPPFLAGS) $(CXXFLAGS) $(INC_DIR) -c -o $@ $(LIBDIR) $< $(LIBRARIES)

.PHONY: clean clean-all
clean:
	rm -rf $(BIN_DIR)

clean-all: clean
	rm -rf *~ 
	rm -rf $(app) $(app_default)

mkbin:
	mkdir $(BIN_DIR)
