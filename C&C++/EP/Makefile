TARGET=electronic_police
OBJECTS=main.o ep_image.o
INCDIR=/usr/local/include/ImageMagick
LIBDIR=/usr/local/lib

$(TARGET):main.o ep_image.o
	g++ -o $(TARGET) $(OBJECTS) -L$(LIBDIR) -lMagick++

main.o:main.cpp
	g++ -c main.cpp -I$(INCDIR)

ep_image.o:ep_image.hpp ep_image.cpp
	g++ -c ep_image.cpp -I$(INCDIR)

clean:
	rm -f $(TARGET) $(OBJECTS)
