# Nome dell'eseguibile
TARGET = Train_Movement

# Compilatore
CC = gcc

# Opzioni di compilazione
CFLAGS = -Wall -Wextra -std=c11

# File sorgenti
SRCS = Train_Movement.c Axle_Counter.c Logger.c

# File oggetto
OBJS = $(SRCS:.c=.o)

# Regola di default per compilare tutto
all: $(TARGET)

# Regola per creare l'eseguibile
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regola per compilare i file oggetto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regola per pulire i file compilati
clean:
	rm -f $(OBJS) $(TARGET)

# Regola per eseguire il programma
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run