from numerical_computing import PolynomialInterpolation,DifferentialInterpolation
from numerical_computing import Trapezoidal,Simpsons,ODES
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

def plot_h_vs_error():
    h = np.float32(1)
    a = 0
    b = 2

    step_size = np.array([],dtype = np.float32)
    error_euler = np.array([],dtype = np.float32)
    error_mod = np.array([],dtype = np.float32)
    error_rk4 = np.array([],dtype = np.float32)

    y = "math.exp(-2*x)+ (1/3)*math.exp(-x)"
    y_prime = "-2*y+math.exp(-x)"
        
    
    
    for i in range(0,11):
        actual_y = eval(y,{"x":b,"math":math})
        
        obj = ODES(y_prime,1,h,a,b)
        
        obj.euler()
        error = abs(actual_y - obj.y[-1])
        error_euler = np.append(error_euler,error)
        
        obj.mod_euler()
        error = abs(actual_y - obj.y[-1])
        error_mod = np.append(error_mod,obj.y[-1])
        
        obj.runge_kutta4()
        error = abs(actual_y - obj.y[-1])
        error_rk4 = np.append(error_rk4,obj.y[-1])
                
        step_size = np.append(step_size,h)
        h = h*0.5
        
        
    plt.plot(step_size,error_euler,label = 'Euler')
    plt.plot(step_size,error_mod,label = 'Mod Euler')
    plt.plot(step_size,error_rk4,label = 'Runge Kutta 4')
    plt.xlabel('Step size (h)')    
    plt.ylabel('Error')   
    plt.title('Step Size VS Error')
    plt.legend()
    plt.show()
        
        

plot_h_vs_error()
