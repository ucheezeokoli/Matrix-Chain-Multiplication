CC = g++

all:
	$(CC) -std=c++11 -o a.exe MCM.cpp

clean:
	rm -f a.exe

