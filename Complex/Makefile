CC = g++
CFLAGS = -c -I.
DEPS = Complex.hpp
TARGET = comp
OBJS = main.o Complex.o 

%.o : %.cpp $(DEPS)
	$(CC) -o $@ $(CFLAGS) $<

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ 