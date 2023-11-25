TARGET = MinimaxCheckers
CC = gcc

# Détection du système d'exploitation
ifeq ($(OS),Windows_NT)
    CFLAGS = -Wall -Wextra -g
    RM = del /f
    TARGET_EXT = .exe
else
    CFLAGS = -Wall -Wextra -fsanitize=address -g
    RM = rm -f
    TARGET_EXT =
endif

SRCS = main.c board.c evaluation.c game_logic.c minimax.c player.c utils.c
OBJS = $(SRCS:.c=.o)
TARGET_BIN = $(TARGET)$(TARGET_EXT)

all: $(TARGET_BIN)

$(TARGET_BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS) $(TARGET_BIN)

test:
	# Ici, tu peux ajouter tes commandes pour exécuter les tests

.PHONY: all clean test
