from .integration import Integration
import numpy as np
from sympy import symbols,diff,sympify

class Simpsons(Integration):
    def __init__(self,x,y):
        return super().__init__(x,y)
    
    @classmethod
    def from_file(cls,filename):
        return super().from_file(filename)
    
    @classmethod
    def from_function(cls,function,a,b,error_bound=1/600,one = True):
        x = symbols('x')
        expr = sympify(function)
        
        fourth_derivative = diff(expr,x,4)
        
        max_point = np.argmax([abs(fourth_derivative.subs(x,i).evalf()) for i in range(a,b+1)])
        
        max_derivative = abs(fourth_derivative.subs(x,max_point).evalf())
        
        constant = 180 if one else 80
        
        h = np.power((constant*error_bound)/(((b-a)**5)*float(max_derivative)),1/4)
        
        n = int((b-a) / h)
        
        if(one):
            while(n%2 != 0):
                n += 1
        else:
            while(n%3 != 0):
                n += 1
        
        x_ = np.linspace(a,b,n+1)
        y_ = np.empty(len(x_),dtype=float)
        for i,idx in enumerate(x_):
            y_[i] = eval(function,{"x": idx})
        
        return cls(x_,y_)
            
        
    def simpson1_3(self):
        integration = self._y[0] + self._y[self._N-1]

        for i in range(1,self._N-1):
            if(i%2 == 1):
                integration += 4*self._y[i]
            else:
                integration += 2*self._y[i]
        
        return integration * (self._h/3)
    
    
    def simpson3_8(self):
        integration = self._y[0] + self._y[self._N-1]
        
        for i in range(1,self._N-1):
            if(i%3):
                integration += 3*self._y[i]
            else:
                integration += 2*self._y[i]

        return integration * ((3*self._h)/8)
    
    
    def __del__(self):
        return super().__del__()
    