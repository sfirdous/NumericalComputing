from numerical_computing import PolynomialInterpolation,DifferentialInterpolation

# obj = PolynomialInterpolation.from_N(5)
# print(obj._x)
# print(obj._y)

# obj = PolynomialInterpolation.from_file('D:/NumericalComputing/NumericalComputing2/data/example1.txt')
# result = obj.cal_diff_table_Norm(True)
# print(result)
# print(obj._x)
# print(obj._y)

# print(obj.newton_interpolation(3.9))

# obj1 = PolynomialInterpolation.from_file('D:/NumericalComputing/NumericalComputing2/data/lagrangeData.txt')
# print(obj1.lagrange_interpolation(5))

# obj2 = DifferentialInterpolation.from_file('D:/NumericalComputing/NumericalComputing2/data/newtonforward.txt')
# print(len(obj2.cal_diff_table()))
# print(obj2._N)

obj3 = DifferentialInterpolation.from_file('D:/NumericalComputing/NumericalComputing2/data/newtondivdiffback.txt')
print(obj3.newton_forward_div_diff(1.5))



