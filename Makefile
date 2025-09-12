BIN_DIR = ./bin/
BIN_SUF = .o
make_bin_path = $(addprefix $(BIN_DIR), $(addsuffix $(BIN_SUF), $(1)))

SRC_DIR = ./src/
SRC_SUF = .cpp
make_src_path = $(addprefix $(SRC_DIR), $(addsuffix $(SRC_SUF), $(1)))

H_DIR = ./include/

CXX = g++
CXX_FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline   \
-Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default  \
-Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy \
-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op                      \
-Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith          \
-Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits           \
-Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE -D__USE_MINGW_ANSI_STDIO

TARGET = $(addprefix $(BIN_DIR), /my_libs.exe)

OBJ = My_stdio My_string My_stdlib main

make_object = $(call make_bin_path, $(1)) : $(call make_src_path, $(1)); \
@$(CXX) $(CXX_FLAGS) -c $$< -I $(H_DIR) -o $$@

.PHONY : all prepare clean

all : prepare $(call make_bin_path, $(OBJ))
	@$(CXX) $(CXX_FLAGS) $(call make_bin_path, $(OBJ)) -o $(TARGET)
	@echo Compilation end

prepare :
	@mkdir -p bin

$(call make_object, My_stdio)

$(call make_object, My_string)

$(call make_object, My_stdlib)

$(call make_object, main)

clean:
	@rm -rf bin
