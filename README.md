# NUMERICALCOMPUTING

**NUMERICALCOMPUTING** is a modular C++ project implementing core numerical methods and scientific computing algorithms.

## Table of Contents

- Overview
- Directory Structure
- Features
- Build Instructions
- Usage
- Dependencies
- Contributing

## Overview

This repository contains several numerical computing modules written in C++, including complex arithmetic, curve fitting, matrix operations and decompositions, polynomial handling, and root finding algorithms. computing development.

## Directory Structure
```
NUMERICALCOMPUTING/

├── Complex/
│ ├── Complex.cpp
│ ├── Complex.hpp
│ ├── main.cpp
│ └── Makefile
├── Interpolation/
│ ├── Interpolation.cpp
│ ├── Interpolation.hpp
│ ├── exponentialFit.cpp
│ ├── LagrangeInterpolation.cpp
│ ├── linearLeastSquaresFit.cpp
│ ├── linearSplineInterpolation.cpp
│ ├── main.cpp
│ ├── Makefile
│ ├── powerFit.cpp
│ ├── quadraticLeastSquaresFit.cpp
│ └── quadraticSplineInterpolation.cpp
├── Matrix/
│ ├── Generic/
│ ├── matrices/
│ ├── Specific/
│ │ ├── CholeskyLUDecomposition.cpp
│ │ ├── CroutLUDecomposition.cpp
│ │ ├── DiagonallyDominance.cpp
│ │ ├── DolittleLUDecomposition.cpp
│ │ ├── FriendFunctions.cpp
│ │ ├── GaussianElimination.cpp
│ │ ├── GaussJacobi.cpp
│ │ ├── GaussSeidel.cpp
│ │ ├── LUSolve.cpp
│ │ ├── main.cpp
│ │ └── Makefile
│ ├── Matrix.cpp
│ ├── Matrix.hpp
│ ├── Operations.cpp
│ ├── OperatorOverloads.cpp
│ └── Properties.cpp
├── Polynomial/
│ ├── main.cpp
│ ├── Makefile
│ ├── Polynomial.cpp
│ └── Polynomial.hpp
├── RootFinding/
│ ├── Bisection.cpp
│ ├── FixedPoint.cpp
│ ├── main.cpp
│ ├── Makefile
│ ├── NewtonRapshon.cpp
│ ├── RootFinding.cpp
│ └── RootFinding.hpp
```


## Features

- **Complex Number Arithmetic:** Basic complex operations implemented in `Complex/`.
- **Curve Fitting:** Linear, quadratic, power, exponential fits, and spline/Lagrange interpolation in `Interpolation/`.
- **Matrix Computations:**
  - LU decompositions (Crout, Doolittle, Cholesky)
  - Matrix properties and operations
  - Gaussian elimination with Gauss-Jacobi and Gauss-Seidel iterative methods
- **Polynomial Operations:** Polynomial creation and manipulation in `Polynomial/`.
- **Root Finding:** Bisection, Newton-Raphson, Fixed-point methods in `RootFinding/`.

## Build Instructions

Compile each module independently using the Makefile inside its directory:

```
cd Complex
make
./ComplexExecutable # example executable name

cd ../Interpolation
make
./InterpolationExecutable
```


## Usage

- Each module’s `main.cpp` provides usage examples and test cases.
- Modify or add data files in the `Interpolation/data/` directory if needed.
- Run compiled executables to test functionalities.

## Dependencies

- Standard C++ compiler (e.g., g++).
- No external dependencies required.

## Contributing

Contributions are welcome! Please fork the repository, add features or fix bugs, and submit a pull request.

---

*This project is intended for education and demonstration of numerical methods in C++.*
