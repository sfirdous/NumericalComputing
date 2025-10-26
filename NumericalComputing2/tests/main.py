from numerical_computing import PolynomialInterpolation,DifferentialInterpolation
from numerical_computing import Trapezoidal,Simpsons,ODES,plot_h_vs_error
from numerical_computing import EigenValuesAndVectors
import numpy as np
import math
import matplotlib.pyplot as plt

# obj = PolynomialInterpolation.from_N(5)
# print(obj._x)
# print(obj._y)

# obj = PolynomialInterpolation.from_file('D:/NumericalComputing/NumericalComputing2/data/example1.txt')
# result = obj.cal_diff_table_Norm(True)
# print(result)
# print(obj._x)
# print(obj._y)

# print(obj.newton_interpolation(3.9))

# obj1 = PolynomialInterpolation.from_file('D:/NumericalComputing/NumericalComputing2/data/lagrangeData.txt')
# print(obj1.lagrange_interpolation(5))

# obj2 = DifferentialInterpolation.from_file('D:/NumericalComputing/NumericalComputing2/data/newtonforward.txt')
# print(len(obj2.cal_diff_table()))
# print(obj2._N)

# obj3 = DifferentialInterpolation.from_file('D:/NumericalComputing/NumericalComputing2/data/newtondivdiffback.txt')
# print(obj3.newton_forward_div_diff(1.5))

# obj4 = DifferentialInterpolation.from_file('D:/NumericalComputing/NumericalComputing2/data/sterling.txt')
# print(obj4.gauss_seterling())



# obj6 = Trapezoidal.from_function("1/(1+x)",0,1)
# print(obj6.trapezoidal())

# obj7 = Simpsons.from_function("1/(1+x)",0,1)
# print(obj7.simpson1_3())

# obj8 = Simpsons.from_function("1/(1+x)",0,1,one=False)
# print(obj8.simpson3_8())

# ivp = ODES("-2*y+math.exp(-x)",1,0.5,0,2)
# ivp.euler()
# print(ivp.y)

# ivp.mod_euler()
# print(ivp.y)

# ivp.runge_kutta4()
# print(ivp.y)

obj9 = EigenValuesAndVectors.from_file('D:/NumericalComputing/NumericalComputing2/data/power_method2.txt')
print(obj9.power_method(1e-6))

# plot_h_vs_error()
