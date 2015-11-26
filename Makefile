PROGRAM=minimd5
CC=gcc
CFLAGS=
SOURCES=minimd5.c md5.c

all: $(PROGRAM)

$(PROGRAM): $(SOURCES)
	$(CC) $(SOURCES) -o $(PROGRAM)

clean:
	rm -rf *.o $(PROGRAM) $(PROGRAM).exe

.PHONY: clean
