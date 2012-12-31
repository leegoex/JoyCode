TARGET=Singleton
OBJECTS=main.o DBConnectionPool.o

$(TARGET):$(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS)

main.o:main.cpp
	g++ -c main.cpp

DBConnectionPool.o:DBConnectionPool.hpp DBConnectionPool.cpp
	g++ -c DBConnectionPool.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)
