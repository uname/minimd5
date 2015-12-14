PROGRAM=minimd5
CC=gcc
CFLAGS=
SOURCES=minimd5.c md5.c
PYMODULE_SOURCES=md5.c pyminimd5.c
PYMODULE_WRAP_SOURCES=pyminimd5_wrap.cxx
PYMODULE_PY=minimd5.py
PYMODULE_SO=_minimd5.so

all: $(PROGRAM)

$(PROGRAM): $(SOURCES)
	$(CC) $(SOURCES) -o $(PROGRAM)

pyminimd5: $(PYMODULE_SOURCES)
	swig -python -c++ pyminimd5.i
	g++ -c pyminimd5.c pyminimd5_wrap.cxx md5.c -I/usr/include/python2.7/ -fPIC
	g++ -shared pyminimd5.o pyminimd5_wrap.o md5.o -o $(PYMODULE_SO)

clean:
	rm -rf *.o *.pyc $(PROGRAM) $(PROGRAM).exe $(PYMODULE_SO) $(PYMODULE_WRAP_SOURCES) $(PYMODULE_PY)

.PHONY: clean
