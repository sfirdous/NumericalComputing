class Polynomail:
    def __init__(self,coefficients):
        self.__coefficients = coefficients
        self.__N = len(self.__coefficients)
    
    def evaluate(self,x):
        for i in range(self.__N):
            result += self.__coefficients[i] * (x**i)
        return result
    
    def derivative(self):
        result = []
        for i in range(1,self.__N):
            result.append(i*self.__coefficients[i])
        return Polynomail(result)
            
            