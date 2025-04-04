void CurveFit::linearLeastSquaresFit(long double &a, long double &b)
{
    long double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for (int i = 0; i < n; ++i)
    {
        sum_x += x_i[i];
        sum_y += f_x_i[i];
        sum_xy += x_i[i] * f_x_i[i];
        sum_x2 += x_i[i] * x_i[i];
    }

    long double mean_x = sum_x / n;
    long double mean_y = sum_y / n;

    long double denom = sum_x2 - n * mean_x * mean_x;
    if (denom == 0)
    {
        std::cerr << "Error: Cannot fit line, denominator is zero.\n";
        a = b = 0;
        return;
    }

    a = (sum_xy - n * mean_x * mean_y) / denom;
    b = mean_y - a * mean_x;
}
