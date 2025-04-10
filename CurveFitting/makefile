CC=g++ 
CCFLAGS=-c 

DEPS=CurveFit.hpp 
TARGET=curve
OBJS=main.o CurveFit.o LagrangesInterpolation.o linearLeastSquaresFit.o quadraticLeastSquaresFit.o exponentialFit.o powerFit.o

%.o: %.cpp $(DEPS) 
	$(CC) -o $@ $(CCFLAGS) $< 
	
$(TARGET): $(OBJS) 
	$(CC) -o $@ $^