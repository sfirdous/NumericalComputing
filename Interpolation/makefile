ifeq ($(OS),Windows_NT)
	RM = del /Q
	TARGET_EXT = .exe 
else 
	RM = rm -f
	TARGET_EXT = 
endif

CC=g++ 
CCFLAGS = -c -I. -I..
DEPS_POLY = ../Polynomial/Polynomial.hpp
DEPS=Interpolation.hpp 
TARGET=curve
OBJS=main.o ../Polynomial/Polynomial.o Interpolation.o LagrangesInterpolation.o linearSplineInterpolation.o linearLeastSquaresFit.o quadraticLeastSquaresFit.o exponentialFit.o powerFit.o

../Polynomial/%.o  : ../Polynomial/%.cpp $(DEPS_POLY)
	$(CC) -o $@ $(CCFLAGS) $<

%.o: %.cpp $(DEPS) 
	$(CC) -o $@ $(CCFLAGS) $< 
	
$(TARGET): $(OBJS) 
	$(CC) -o $@ $^

clean:
	$(RM) $(OBJS) $(TARGET)$(TARGET_EXT)