TARGET=current_time
OBJECTS=main.o

$(TARGET):$(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) -lboost_date_time

main.o:main.cpp
	g++ -c main.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)
