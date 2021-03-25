#Makefile
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
OUT_DIR := out

EXE := $(BIN_DIR)/interpreter
SRC := $(wildcard $(SRC_DIR)/*.cc)
OBJ := $(SRC:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)

CPPFLAGS := -Iinclude -I.
CFLAGS   := -g -std=c++14
LDFLAGS  := -Llib
LDLIBS   := -lm
CC		:= g++
.PHONY: all clean

all: $(EXE)


$(EXE):  $(OBJ) | $(BIN_DIR) $(OUT_DIR)
	@echo
	@echo Create $@
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	@echo
	@echo Compile $<
	$(CC) $(CPPFLAGS) $(CFLAGS) -MD -c $< -o $@

	@sed -e 's/\#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' -e '/^$$/ d' -e 's/$$/ :/' < obj/$*.d>> obj/$*.d

$(BIN_DIR) $(OBJ_DIR) $(OUT_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)  $(OUT_DIR)

-include $(OBJ:.o=.d)