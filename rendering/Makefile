SRCS := $(wildcard ./src/*.cpp)
OBJS := $(SRCS:cpp=o)
OBJS := $(subst ./src/,, $(OBJS))


all: $(OBJS)

%.o: ./src/%.cpp ./inc/%.h
	g++ -c $< -I/opt/vc/include -I./inc -I../lodepng/inc

clean:
	rm *.o
