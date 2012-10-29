CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=automate.exe
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

automate.exe: $(OBJ)
    $(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
    $(CC) -o $@ -c $< $(CFLAGS)

clean:
        rm -rf *.o
