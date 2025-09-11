class Interpolation:
    def __init__(self,x,y):
        self._x = x
        self._y = y
        self._n = len(x)
    
    @classmethod
    def from_n(cls,n):
        x = [0] * n
        y = [0]  * n
        for i in range(0,n):
            x[i] = float(input(f"Enter x[{i}]: "))
            y[i] = float(input(f"Enter y[{i}]: "))
        return cls(x,y)
    

    def cal_diff_table(self,forward = True):
        y = {}                            # dict to store deltas
        forward_val = []                  # list that contains forward values
        backward_val = []                 # list that contains backward values
         
        y['y0'] = self._y                 # y0 = y
        
        for i in range(1,self._n):        
            y[f'y{i}'] = [0] * (self._n - i)                                                          # add key yi in dict with size n-i
            
            for j in range(self._n - i):
                y[f'y{i}'][j] = (y[f'y{i-1}'][j+1] - y[f'y{i-1}'][j]) / (self._x[i+j] - self._x[j])   # calculate the jth entry for yi
                
            forward_val.append(y[f'y{i}'][0])                                                         # add first value of yi to forward_val
            backward_val.append(y[f'y{i}'][self._n-i-1])                                              # add last value of yi to backward_val
                
        return forward_val if forward else backward_val                                               # return forward or backward values based on the forward parameter

            
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
    
class PolynomialInterpolation(Interpolation):
    
    def __init__(self,x,y):
        super().__init__(x,y)
    
    @classmethod
    def from_n(cls, n):
        return super().from_n(n)
    
    @classmethod
    def from_file(cls, filename):
        return super().from_file(filename)
    
    def newton_interpolation(self,x):
        forward_val = self.cal_diff_table(True)
        
        result = self._y[0]
        
        for i in range(0,len(forward_val)):
            term = x - self._x[0]
            for j in range (1,i+1):
                term *= x - self._x[j]
            result += forward_val[i] * term
            
        return result
    
    def lagrange_interpolation(self,x):
        result = 0
        for i in range(0,self._n):
            term = self._y[i]
            for j in range(0,self._n):
                if(i!=j):
                    term *= (x  - self._x[j]) / (self._x[i] - self._x[j])
            result += term
        return result
        
    
    
    
    