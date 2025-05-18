ifeq ($(OS),Windows_NT)
	RM = del /Q
	TARGET_EXT = .exe 
else 
	RM = rm -f
	TARGET_EXT = 
endif
   
CC = g++
CFLAGS = -c -I.
DEPS = Polynomial.hpp
OBJS = main.o Polynomial.o
TARGET = poly

%.o : %.cpp $(DEPS)
	$(CC) -o $@ $(CFLAGS) $<

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ 

clean:
	$(RM) $(OBJS) $(TARGET)$(TARGET_EXT)

