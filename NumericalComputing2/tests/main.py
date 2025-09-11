from numerical_computing import PolynomialInterpolation,DifferentialInterpolation

# obj = PolynomialInterpolation.from_n(5)
# print(obj._x)
# print(obj._y)

obj = PolynomialInterpolation.from_file('/workspaces/NumericalComputing/NumericalComputing2/data/example1.txt')
result = obj.cal_diff_table_norm(True)
# print(result)
# print(obj._x)
# print(obj._y)

print(obj.newton_interpolation(3.9))

obj1 = PolynomialInterpolation.from_file('/workspaces/NumericalComputing/NumericalComputing2/data/lagrangeData.txt')
print(obj1.lagrange_interpolation(5))

obj2 = DifferentialInterpolation.from_file('/workspaces/NumericalComputing/NumericalComputing2/data/newtonforward.txt')
print(obj2.newton_backward())

# obj3 = DifferentialInterpolation.from_file('/workspaces/NumericalComputing/NumericalComputing2/data/sterling.txt')
# obj3.sterling()


