ifeq ($(OS),Windows_NT)
	RM = del /Q
	TARGET_EXT = .exe
else
	RM = rm -f
	TARGET_EXT =
endif

CC = g++
CFLAGS = -c -I. -I..
DEPS_POLY = ../Polynomial/Polynomial.hpp
DEPS = RootFinding.hpp 
OBJS = main.o ../Polynomial/Polynomial.o RootFinding.o Bisection.o NewtonRaphson.o FixedPoint.o
TARGET = root


../Polynomial/%.o  : ../Polynomial/%.cpp $(DEPS_POLY)
	$(CC) -o $@ $(CFLAGS) $<

%.o : %.cpp $(DEPS)
	$(CC) -o $@ $(CFLAGS) $<

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

clean: 
	$(RM) $(OBJS) $(TARGET)$(TARGET_EXT) 