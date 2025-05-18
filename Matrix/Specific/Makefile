ifeq ($(OS),Windows_NT)
	RM = del /Q
	TARGET_EXT = .exe 
else 
	RM = rm -f
	TARGET_EXT = 
endif

CC = g++
CFLAGS = -c -I.
TARGET = matrix
DEPS = Matrix.hpp
OBJS = main.o Matrix.o GaussianElimination.o FriendFunctions.o Properties.o DolittleLUDecomposition.o CroutLUDecomposition.o CholeslyLUDecomposition.o DiagonallyDominance.o GaussJacobi.o GaussSeidel.o

%.o : %.cpp $(DEPS)
	$(CC) -o $@ $(CFLAGS) $<

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

clean:
	$(RM) $(OBJS) $(TARGET)$(TARGET_EXT)