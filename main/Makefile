CXX      := clang++
CXXFLAGS := -pedantic-errors -Wall -Wextra -std=c++23
LDFLAGS	 := 
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := main
INCLUDE  := -Iinclude/
SRC      := $(wildcard src/*.cpp)

LIBS := util
LIBS_DIR := ../util_lib/build/libs/
INCLUDE += -I../util_lib/include/
# LDFLAGS += -L$(LIBS_DIR) -l$(LIBS) -Wl,-rpath,/Users/artembolshov/Desktop/Programming/test/cpp/linking/util_lib/build/libs/ # solution with abs path
LDFLAGS += -L$(LIBS_DIR) -l$(LIBS) # solution with @executable_path

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES := $(OBJECTS:.o=.d)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g -fsanitize=address,undefined,leak
debug: all

release: CXXFLAGS += -O3 -march=native -flto=auto
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

info:
	@echo "[*] Libraries: "
	@$(foreach item, ${APP_DIR}, echo "\t$(item)";)
	@echo "[*] Object dir: "
	@$(foreach item, ${OBJ_DIR}, echo "\t$(item)";)
	@echo "[*] Sources: "
	@$(foreach item, ${SRC}, echo "\t$(item)";)
	@echo "[*] Objects: "
	@$(foreach item, ${OBJECTS}, echo "\t$(item)";)
	@echo "[*] Dependencies: "
	@$(foreach item, ${DEPENDENCIES}, echo "\t$(item)";)
