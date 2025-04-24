CC=g++ 
CCFLAGS=-c 

DEPS=CurveFit.hpp 
TARGET=curve
OBJS=main.o CurveFit.o LagrangesInterpolation.o linearLeastSquaresFit.o exponentialFit.o powerFit.o  quadraticLeastSquaresFit.o linearSplineInterpolation.o quadraticSplineInterpolation.o 

%.o: %.cpp $(DEPS) 
	$(CC) -o $@ $(CCFLAGS) $< 
	
$(TARGET): $(OBJS) 
	$(CC) -o $@ $^