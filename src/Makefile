#gcc test_ock.c -g -O0 -o test_ock -lopencryptoki -ldl\
-I /usr/include/opencryptoki/

PROJ=password-manager

C_SOURCE=$(wildcard *.c)

H_SOURCE=$(wildcard *.h)

OBJ=$(C_SOURCE:.c=.o)

CC = gcc
INCLUDE_PATH = /usr/include/opencryptoki/

CC_FLAGS=-c \
		 -W \
		 -Wall \
		 -lopencryptoki \
		 -ldl \
		 -I $(INCLUDE_PATH)

all: $(PROJ) clean

$(PROJ): $(OBJ)
	$(CC) -g -O0 -o $@ $^

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

main.o: main.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf *.o

.PHONY: all clean