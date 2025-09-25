from .integration import Integration
import numpy as np
from sympy import symbols,diff,sympify

class Trapezoidal(Integration):
    def __init__(self,x,y):
        return super().__init__(x,y)
    
    @classmethod
    def from_file(cls,filename):
        return super().from_file(filename)
    
    @classmethod
    def from_function(cls,function,a,b,error_bound=1/600,n=None,h=None):
        x = symbols('x')
        expr = sympify(function)
        
        second_derivative = diff(expr,x,2)
        print(f'Derivative: {second_derivative}')
        
        max_point = np.argmax([abs(second_derivative.subs(x,i).evalf()) for i in range(a,b+1)])
        
        max_derivative = abs(second_derivative.subs(x,max_point).evalf())
       
        h = np.sqrt((12*error_bound)/((b-a)*float(max_derivative)))
        # print(h)
        
        n = int((b-a) / h)
        # print(n)
        x_ = y_ = np.empty(n,dtype = float)
        for i,idx in enumerate(np.arange(a,b,h)):
            x_[i] = idx
            y_[i] = eval(function,{"x": idx})
        return cls(x_,y_)
            
        
    # def calculate_h(self,accuracy=)
    def trapezoidal(self):
        integration = self.__y[0] + self.__y[self.__N-1]
        
        for i in range(1,self.__N-1):
            integration += 2*self.__y[i]
        
        return integration * (self.__h / 2)
    
    
    def __del__(self):
        return super().__del__()
    