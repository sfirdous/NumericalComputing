from numerical_computing import PolynomialInterpolation

# obj = PolynomailInterpolation.from_n(5)
# print(obj._x)
# print(obj._y)

obj = PolynomialInterpolation.from_file('D:/NumericalComputing/NumericalComputing2/data/example1.txt')
# result = obj.cal_diff_table(True)
# print(result)
# print(obj._x)
# print(obj._y)

print(obj.newton_interpolation(3.9))

obj1 = PolynomialInterpolation.from_file('D:/NumericalComputing/NumericalComputing2/data/lagrangeData.txt')
print(obj1.lagrange_interpolation(5))
