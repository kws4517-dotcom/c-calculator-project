CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -Iinclude
TARGET=calculator
TEST_TARGET=test_calculator

SRC_DIR=src
TEST_DIR=tests

SRCS=$(SRC_DIR)/main.c $(SRC_DIR)/add.c $(SRC_DIR)/sub.c $(SRC_DIR)/mul.c $(SRC_DIR)/div.c $(SRC_DIR)/print_result.c
TEST_SRCS=$(TEST_DIR)/test_calc.c $(SRC_DIR)/add.c $(SRC_DIR)/sub.c $(SRC_DIR)/mul.c $(SRC_DIR)/div.c $(SRC_DIR)/print_result.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRCS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRCS)

run: $(TARGET)
	./$(TARGET)

ifeq ($(OS),Windows_NT)
clean:
	del /Q $(TARGET).exe $(TEST_TARGET).exe 2>nul
else
clean:
	rm -f $(TARGET) $(TEST_TARGET) $(TARGET).exe $(TEST_TARGET).exe
endif

re: clean all

