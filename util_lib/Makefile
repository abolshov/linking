CXX      := clang++
CXXFLAGS := -pedantic-errors -Wall -Wextra -fPIC -std=c++23
LDFLAGS	 := -shared
BUILD    := build
OBJ_DIR  := $(BUILD)/objects
LIB_DIR  := $(BUILD)/libs
TARGET   := libutil.so
INCLUDE  := -Iinclude/
SRC      := $(wildcard src/*.cpp)

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES := $(OBJECTS:.o=.d)

all: build $(LIB_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(LIB_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(LIB_DIR)/$(TARGET) $^ $(LDFLAGS) -Wl,-install_name,'@executable_path/../../../util_lib/$(LIB_DIR)/$(TARGET)' # solution with @executable_path
# 	$(CXX) $(CXXFLAGS) -o $(shell pwd)/$(LIB_DIR)/$(TARGET) $^ $(LDFLAGS) # solution with absolute path

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info

build:
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g -fsanitize=address,undefined,leak
debug: all

release: CXXFLAGS += -O3 -march=native -flto=auto
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(LIB_DIR)/*

info:
	@echo "[*] Libraries: "
	@$(foreach item, ${LIB_DIR}, echo "\t$(item)";)
	@echo "[*] Object dir: "
	@$(foreach item, ${OBJ_DIR}, echo "\t$(item)";)
	@echo "[*] Sources: "
	@$(foreach item, ${SRC}, echo "\t$(item)";)
	@echo "[*] Objects: "
	@$(foreach item, ${OBJECTS}, echo "\t$(item)";)
	@echo "[*] Dependencies: "
	@$(foreach item, ${DEPENDENCIES}, echo "\t$(item)";)
