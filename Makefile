CC = g++
AR = ar
CFLAGS = -fPIC $(shell sdl2-config --cflags) -IDeps/include/
LDFLAGS_SHARED = -shared $(shell sdl2-config --libs)
LDFLAGS_STATIC = $(shell sdl2-config --libs)

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SOURCES = $(shell find $(SRC_DIR)/ -name "*.cpp")
HEADERS = $(shell find $(SRC_DIR)/ -name "*.h")
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

SHARED = $(BIN_DIR)/libKlaoudeEngine.so
STATIC = $(BIN_DIR)/libKlaoudeEngine.a

all: $(SHARED) $(STATIC)

$(STATIC): $(OBJECTS)
	mkdir -p $(@D)
	$(AR) -cvq $(STATIC) $(OBJ_DIR)/*.o
	$(AR) -t $(STATIC)

$(SHARED): $(OBJECTS)
	mkdir -p $(@D)
	$(CC) -o $(SHARED) $(OBJ_DIR)/*.o $(LDFLAGS_SHARED)

.SECONDEXPANSION:

$(OBJECTS): $$(patsubst $(OBJ_DIR)/%.o,$(SRC_DIR)/%.cpp,$$@)
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS)
