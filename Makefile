CC=gcc
CFLAGS=-Wall -I/usr/local/include
LIBS=-L/usr/local/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS=first.c
OBJS=$(SRCS:.c=.o)
EXEC=first

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

