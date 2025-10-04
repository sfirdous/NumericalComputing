from abc import ABC

class Integration(ABC):
    def __init__(self,x,y):
        self._x = x
        self._y = y
        self._N = len(x)
        self._a = self._x[0]
        self._b = self._x[self._N-1]
        self._h = (self._b - self._a) / (self._N-1)
        print(self._x)
        print(self._y)
     
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
    
    @classmethod
    def from_function(cls,function,a,b,error_bound):
        pass 
    
    def simpson3_8(self):
        integration = self.__y[0] + self.__y[self.__N-1]
        
        for i in range(1,self.__N-1):
            if(i%3):
                integration += 3*self.__y[i]
            else:
                integration += 2*self.__y[i]

        return integration * ((3*self.__h)/8)
    
    
    def __del__(self):
        del self._x
        del self._y
        del self._N
        del self._a
        del self._b
            
        

        