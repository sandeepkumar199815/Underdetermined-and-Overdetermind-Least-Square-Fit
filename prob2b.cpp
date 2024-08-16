#include <armadillo>
#include <iostream>

using namespace arma;

int
main(void)
{
	
	mat A = " -1 1 1 0";
	A.print("A: ");
	vec y_desired = "-1";
	vec x = solve(A, y_desired);
	x.print("x_ln: ");
	vec y = conv(vec("1 1 -1 -1"), x);
	y.print("y: ");
	return 0;
}