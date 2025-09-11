class Polynomail:
    def __init__(self,coefficients):
        self.__coefficients = coefficients
        self.__n = len(self.__coefficients)
    
    def evaluate(self,x):
        for i in range(self.__n):
            result += self.__coefficients[i] * (x**i)
        return result
    
    def derivative(self):
        result = []
        for i in range(1,self.__n):
            result.append(i*self.__coefficients[i])
        return Polynomail(result)
            
            