OBJS := $(wildcard ../window/*.o)
OBJS := $(OBJS) $(wildcard ../rendering/*.o)
OBJS := $(OBJS) $(wildcard ../lodepng/*.o)
OBJS := $(OBJS) $(wildcard ../gui/*.o)

gui: main.o $(OBJS)
	g++ main.o $(OBJS) -o gui -L/opt/vc/lib -lbcm_host -lbrcmEGL -lbrcmGLESv2

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp -I/opt/vc/include -I../window/inc -I../gui/inc -I../rendering/inc

clean:
	rm gui *.o
