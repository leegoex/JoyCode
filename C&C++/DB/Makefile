SqliteDemo:main.o DBConnection.o
	g++ -o SqliteDemo main.o DBConnection.o -lsqlite3

main.o:main.cpp DBConnection.h
	g++ -c main.cpp

DBConnection.o:DBConnection.cpp DBConnection.h
	g++ -c DBConnection.cpp

clean:
	rm -f SqliteDemo *.o

