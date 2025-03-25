# Directories to work with
SRC_DIR = .
TEST_DIR = tests

# Compiler
CC=clang

# Important (making object) flags
CFLAGS=-c -D _DEBUG -ggdb3 -Wall -Wextra -Weffc++ -Wcast-align -Wcast-qual -Wchar-subscripts -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wsign-promo -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -fcheck-new -fsized-deallocation -fstack-check -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -fPIE -O0

# Linker flags
LDFLAGS=-lm
MOCKFLAG = -lcmocka

# Sources to make object files to pack bin
MAIN = $(SRC_DIR)/main.c 
SOURCES = $(SRC_DIR)/floating_arithmetic.c $(SRC_DIR)/reading_lines.c $(SRC_DIR)/solve_equation.c $(SRC_DIR)/user_interface.c 
SOURCES_TEST = $(TEST_DIR)/main_test.c $(TEST_DIR)/test_arithmetic.c

# Just pick up SOURCES and change extension to .o (objects)
MAIN_O = $(MAIN:.c=.o)
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_TEST = $(SOURCES_TEST:.c=.o)

EXECUTABLE = $(SRC_DIR)/bin
TESTS = $(TEST_DIR)/test

.PHONY: clean build run test

build: $(EXECUTABLE) # TODO: prefer separate task for building

run: $(EXECUTABLE)
	./$(EXECUTABLE)

test: $(TESTS)
	./$(TESTS)

$(EXECUTABLE): $(MAIN_O) $(OBJECTS)
	$(CC) $(LDFLAGS) $(MAIN_O) $(OBJECTS) -o $@

$(TESTS): $(OBJECTS_TEST) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS_TEST) $(OBJECTS) -o $@ $(MOCKFLAG)


$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(MAIN_O) $(OBJECTS) $(EXECUTABLE)
	rm -rf $(OBJECTS_TEST) $(TESTS)
