CYAN = \033[0;36m
RESET = \033[0m

CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = donut
SRC = donut.c

all: $(TARGET)

$(TARGET): $(SRC)
	@echo "$(CYAN)Compiling program...$(RESET)"
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRC) -lm

run: $(TARGET)
	@echo "$(CYAN)Running program...$(RESET)"
	@./$(TARGET)

clean:
	@echo "$(CYAN)Cleaning up...$(RESET)"
	@rm -f $(TARGET)
