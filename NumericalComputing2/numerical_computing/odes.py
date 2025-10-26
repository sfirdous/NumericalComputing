import numpy as np
import math
import matplotlib.pyplot as plt

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