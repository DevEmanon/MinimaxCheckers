TARGET = MinimaxCheckers

CC = gcc

CFLAGS = -Wall -Wall -Wextra -fsanitize=address -g

SRCS = main.c board.c evaluation.c game_logic.c minimax.c player.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

test:
	# Ici, tu peux ajouter tes commandes pour exécuter les tests

.PHONY: all clean test
