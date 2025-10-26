import torch
from torch import Tensor

class EigenValuesAndVectors:
    def __init__(self,A:Tensor,v:Tensor):
        self.__A = A
        self.__v = v
    
    @classmethod
    def from_file(cls,filename):
        with open(filename,"r") as file:
            line = file.readline().strip().split()
            m,n = int(line[0]),int(line[1])
            A = torch.zeros(m,n)
            v = torch.zeros(n)
            # populate matrix A
            for i in range(m):
                row = file.readline().strip().split()
                for j in range(n):
                    A[i,j] = float(row[j])
            
            # populate initial vector v
            column = file.readline().strip().split()
            for j in range(n):
                v[j] = float(column[j])
            
        return cls(A,v)

    def power_method(self,tol):
        
        prev_eigen_val = torch.max(self.__v).item()
        x = self.__A @ self.__v
        dom_eigen_val = torch.max(x).item()
        x = x/dom_eigen_val
        
        error = abs(dom_eigen_val - prev_eigen_val)
        while(error > tol):
            x = self.__A @ x
            prev_eigen_val = dom_eigen_val
            dom_eigen_val = torch.max(x).item()
            x = x/dom_eigen_val
            error = abs(dom_eigen_val - prev_eigen_val)
        return dom_eigen_val
        
        
                    
            
        