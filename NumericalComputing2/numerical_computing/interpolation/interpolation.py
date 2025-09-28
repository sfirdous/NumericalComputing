import math
from abc import ABC

class Interpolation(ABC):
    def __init__(self,x,y):
        self._x = x
        self._y = y
        self._N = len(x)
    
    @classmethod
    def from_N(cls,n):
        x = [0] * n
        y = [0]  * n
        for i in range(0,n):
            x[i] = float(input(f"Enter x[{i}]: "))
            y[i] = float(input(f"Enter y[{i}]: "))
        return cls(x,y)

            
    @classmethod
    def from_file(cls,filename):
        with open(filename,"r") as file:
            n = int(file.readline().strip())
            x = []
            y = []    
            for _ in range(n):
                line = file.readline().strip().split() 
                x_value , y_value = float(line[0]) ,float(line[1])
                x.append(x_value)
                y.append(y_value)    
        return cls(x,y)
    
    def __del__(self):
        del self._x
        del self._y
        del self._N
    
class PolynomialInterpolation(Interpolation):
    
    def __init__(self,x,y):
        super().__init__(x,y)
    
    @classmethod
    def from_N(cls, n):
        return super().from_N(n)
    
    @classmethod
    def from_file(cls, filename):
        return super().from_file(filename)
    
    def cal_diff_table_Norm(self,forward = True):
        y = {}                            # dict to store deltas
        forward_val = []                  # list that contains forward values
        backward_val = []                 # list that contains backward values
         
        y['y0'] = self._y                 # y0 = y
        
        for i in range(1,self._N):        
            y[f'y{i}'] = [0] * (self._N - i)                                                          # add key yi in dict with size n-i
            
            for j in range(self._N - i):
                y[f'y{i}'][j] = (y[f'y{i-1}'][j+1] - y[f'y{i-1}'][j]) / (self._x[i+j] - self._x[j])   # calculate the jth entry for yi
                
            forward_val.append(y[f'y{i}'][0])                                                         # add first value of yi to forward_val
            backward_val.append(y[f'y{i}'][self._N-i-1])                                              # add last value of yi to backward_val
                
        return forward_val if forward else backward_val                                               # return forward or backward values based on the forward parameter
    
    

    def newton_interpolation(self,x):
        forward_val = self.cal_diff_table_Norm(True)
        
        result = self._y[0]
        
        for i in range(0,len(forward_val)):
            term = x - self._x[0]
            for j in range (1,i+1):
                term *= x - self._x[j]
            result += forward_val[i] * term
            
        return result
    
    def lagrange_interpolation(self,x):
        result = 0
        for i in range(0,self._N):
            term = self._y[i]
            for j in range(0,self._N):
                if(i!=j):
                    term *= (x  - self._x[j]) / (self._x[i] - self._x[j])
            result += term
        return result
    
    def __del__(self):
        super().__del__()
        
class DifferentialInterpolation(Interpolation):
    def __init__(self,x,y):
        super().__init__(x,y)
    
    @classmethod
    def from_N(cls, n):
        return super().from_N(n)
    
    @classmethod
    def from_file(cls, filename):
        return super().from_file(filename)
    
    def cal_diff_table(self):
        y = {}                                                                                        # dict to store deltas
        forward_val = []                                                                              # list that contains forward values
        backward_val = []                                                                             # list that contains backward values
         
        y['y0'] = self._y                                                                             # y0 = y
        
        for i in range(1,self._N):        
            y[f'y{i}'] = [0] * (self._N - i)                                                          # add key yi in dict with size n-i
            
            for j in range(self._N - i):
                y[f'y{i}'][j] = (y[f'y{i-1}'][j+1] - y[f'y{i-1}'][j])                                 # calculate the jth entry for yi
                
            forward_val.append(y[f'y{i}'][0])                                                         # add first value of yi to forward_val
            backward_val.append(y[f'y{i}'][self._N-i-1])                                              # add last value of yi to backward_val
                
        return forward_val , backward_val,y 

    
    def newton_forward(self):
        h = (self._x[1] - self._x[0])

        forward_val = self.cal_diff_table()[0] 

        sum = 0 
        for i in range(0,len(forward_val)):
            if(i%2):
                sum += forward_val[i] / math.factorial(i+1)
            else:
                sum -= forward_val[i] / math.factorial(i+1)

        return sum / h 

    
    def newton_backward(self):
        h = (self._x[1] - self._x[0])

        backward_val = self.cal_diff_table()[1]

        sum = 0 
        for i in range(0,len(backward_val )):
            sum += backward_val [i] / math.factorial(i+1)

        return sum / h 
    
    def P(self,n,u,forward = True):
        sum_f = 0
        sum_b = 0
        for j in range(1,n):
            term_f = term_b = 1
            for k in range(0,n+1):
                term_f *= (u-k)
                term_b *= (u+k)
            sum_f += term_f
            sum_b += term_b
        return (sum_f if forward else sum_b) / math.factorial(n) 
    

    def newton_forward_div_diff(self,x):
        h = self._x[1] - self._x[0]
        u = (x - self._x[0]) / h
        
        
        forward_val = self.cal_diff_table()[0]
        result = forward_val[0]
        
        for i in range (1,self._N - 1):
            result +=   self.P(i,u) * forward_val[i]
            
        return result / h

    def newton_backward_div_diff(self,x):
        h = self._x[1] - self._x[0]
        u = ( x - self._x[self._N-1] ) / h
        

        backward_val = self.cal_diff_table()[1]
        result = backward_val[0]

        for i in range (1,self._N - 1):
            result +=   self.P(i,u,False) * backward_val[i]
            
        return result / h
    
    def gauss_seterling(self):
        h = self._x[1] - self._x[0]
        
        mid = self._N // 2
        
        derivative = 0                          
        
        factorial = 1
        sign = 1
        forward_val,backward_val,y= self.cal_diff_table()
        
        for i in range(1,self._N,2):
            factorial *= i if i > 1 else 1
            diff_avg = (forward_val[i-1] + backward_val[i-1]) / 2
            term = (sign * diff_avg) / (factorial*h)
            derivative += term
            sign *= -1
                
        return derivative
        
           
    def __del__(self):
        super().__del__()
    
    


    
    
    