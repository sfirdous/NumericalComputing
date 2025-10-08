import numpy as np
import math

class ODES:
    def __init__(self,function,y0,h,a,b):
        self.__function = function
        self.__y0 = y0
        self.__h = h
        self.__a = a
        self.__b = b
        self.__n = int((b-a)/h)
        self.x = np.linspace(self.__a,self.__b,self.__n+1)
        self.y = np.zeros(len(self.x))
        self.y[0] = self.__y0
    
    def euler(self):    
        for i in range(len(self.x)-1):
            self.y[i+1] = self.y[i] + self.__h* eval(self.__function,{"x":self.x[i],"y":self.y[i],"math":math})
        
    def mod_euler(self):  
        for i in range(len(self.x)-1):
            k1 = eval(self.__function,{"x":self.x[i],"y":self.y[i],"math":math})
            y_ = self.y[i] + self.__h*k1
            k2 = eval(self.__function,{"x":self.x[i+1],"y":y_,"math":math})
            
            self.y[i+1] = self.y[i] + (self.__h / 2 )*(k1+k2)
        
    def runge_kutta4(self):
        for i in range(len(self.x)-1):
            k1 = self.__h* eval(self.__function,{"x":self.x[i],"y":self.y[i],"math":math})
            k2 = self.__h * eval(self.__function,{"x":self.x[i] + 0.5*self.__h,"y":self.y[i]+0.5*k1,"math":math})
            k3 = self.__h * eval(self.__function,{"x":self.x[i] + 0.5*self.__h,"y":self.y[i]+0.5*k2,"math":math})
            k4 = self.__h * self.__h * eval(self.__function,{"x":self.x[i] + self.__h,"y":self.y[i]+k3,"math":math})
            self.y[i+1] = self.y[i] + (1/6)*(k1+2*k2+2*k3+k4) 
            
        
        