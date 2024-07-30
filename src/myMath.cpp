static
double notEqual(double n1, double n2)
{
	n1 -= n2;
	return ((n1 < 0 ? -n1 : n1) > 0.0000001);
}
// this is a custom implementation of the sqrt function
// https://en.wikipedia.org/wiki/Newton%27s_method#Use_of_Newton's_method_to_compute_square_roots
// we want to find the roots of the function f(x) = x^2 - a
// as we want to find the square root of a
// the derivative of f(x) is f'(x) = 2x
// the newton's method formula is x_n+1 = x_n - f(x_n) / f'(x_n)
// so x_n+1 = x_n - (x_n^2 - a) / 2x_n
// so x_n+1 = (x_n + a / x_n) / 2
double	sqrt(double x)
{
	double	x_n;
	double	x_n1 = x;

	do
	{
		x_n = x_n1;
		x_n1 = (x_n + x / x_n) / 2;
	}	while (notEqual(x_n, x_n1));
	return x_n;
}

int pow(int base, int exp)
{
	int result = 1;
	
	for (int i = 0; i < exp; i++)
		result *= base;
	return result;
}