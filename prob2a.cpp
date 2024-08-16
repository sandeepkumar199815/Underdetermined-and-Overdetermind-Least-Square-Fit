#include <armadillo>
#include <iostream>

using namespace arma;

int
main(void)
{
	// Desired y = [1, 2, -1, -4, -1, 2, 1]
	// h = [1, 1, -1, -1]
	// x = length 3
	mat A = "1 0 0 0; 1 1 0 0; -1 1 1 0; -1 -1 1 1; 0 -1 -1 1; 0 0 -1 -1; 0 0 0 -1";
	A.print("A: ");
	vec y_desired = "1 2 -1 -4 -1 2 1";
	vec x = solve(A, y_desired);
	x.print("x_ln: ");
	vec y = conv(vec("1 1 -1 -1"), x);
	y.print("y: ");
	return 0;
}
