SRCS := $(wildcard ./src/*.cpp)
OBJS := $(SRCS:cpp=o)
OBJS := $(subst ./src/,, $(OBJS))


all: $(OBJS)

%.o: ./src/%.cpp ./inc/%.h
	g++ -c $< -I./inc -I../rendering/inc -I/opt/vc/include

clean:
	rm *.o
