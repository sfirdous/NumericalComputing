from .integration import Integration
import numpy as np
from sympy import symbols,diff,sympify

class Simpsons1(Integration):
    def __init__(self,x,y):
        return super().__init__(x,y)
    
    @classmethod
    def from_file(cls,filename):
        return super().from_file(filename)
    
    @classmethod
    def from_function(cls,function,a,b,error_bound=1/600):
        x = symbols('x')
        expr = sympify(function)
        
        fourth_derivative = diff(expr,x,4)
        print(f'Derivative: {fourth_derivative }')
        
        max_point = np.argmax([abs(fourth_derivative .subs(x,i).evalf()) for i in range(a,b+1)])
        
        max_derivative = abs(fourth_derivative.subs(x,max_point).evalf())
       
        h = np.power((180*error_bound)/((b-a)*float(max_derivative)),1/4)
        print(h)
        
        n = int((b-a) / h)
        print(n)
        x_ = np.linspace(a,b,n+1)
        y_ = np.empty(len(x_),dtype=float)
        for i,idx in enumerate(x_):
            y_[i] = eval(function,{"x": idx})
        
        return cls(x_,y_)
            
        
    def simpson1_3(self):
        integration = self.__y[0] + self.__y[self.__N-1]

        for i in range(1,self.__N-1):
            if(i%2 == 1):
                integration += 4*self.__y[i]
            else:
                integration += 2*self.__y[i]
        
        return integration * (self.__h/3)
    
    
    def __del__(self):
        return super().__del__()
    