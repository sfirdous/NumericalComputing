from numerical_computing import Polynomail

class Integration():
    def __init__(self,x,y,a,b):
        self.__x = x
        self.__y = y
        self.__N = len(x)
        self.__a = self.__x[0]
        self.__b = self.__x[self.__N-1]
        self.__h = (self.__b - self.__a) / (self.__N-1)
     
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
        del self.__x
        del self.__y
        del self.__N
        del self.__a
        del self.__b
    
    def trapezoidal(self):
        integration = self.__y[0] + self.__y[self.__N-1]
        
        for i in range(1,self.__N-1):
            integration += 2*self.__y[i]
        
        return integration * (self.__h / 2)
    
    def simpson3_8(self):
        integration = self.__y[0] + self.__y[self.__N-1]
        
        for i in range(1,self.__N-1):
            if(i%3):
                integration += 3*self.__y[i]
            else:
                integration += 2*self.__y[i]

        return integration * ((3*self.__h)/8)
    
    def simpson1_3(self):
        integration = self.__y[0] + self.__y[self.__N-1]

        for i in range(1,self.__N-1):
            if(i%2 == 1):
                integration += 4*self.__y[i]
            else:
                integration += 2*self.__y[i]
        
        return integration * (self.__h/3)
            
        

        