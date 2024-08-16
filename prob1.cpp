#include <armadillo>
#include <iostream>

using namespace arma;

int
main(void)
{
	 mat A;
    A.load("data_1.txt", raw_ascii);
	A.print("A: ");
	vec A1 = A.col(0);
	vec A2 = A.col(1);
	vec A3 = exp(-A1);
	mat B ;
	B = join_horiz(ones(1001),A1,A3);
	B.print("B: ");
	vec C = solve(B , A2);
	C.print("C: ");
    vec y = B * C ;

    mat D;
    D.load("data_2.txt", raw_ascii);
	D.print("D: ");
	vec D1 = D.col(0);
	vec D2 = D.col(1);
	vec D3 = exp(-D1);
	mat E;
	E = join_horiz(ones(1001),D1,D3);
	E.print("E: ");
	vec F = solve(E , D2);
	F.print("F: ");
    vec p = E * F ;

    mat G;
    G.load("data_2.txt", raw_ascii);
	G.print("G: ");
	vec G1 = G.col(0);
	vec G2 = G.col(1);
	vec G3 = exp(-G1);
	mat H ;
	H = join_horiz(ones(1001),G1,G3);
	H.print("H: ");
	vec I = solve(H , G2);
	I.print("I: ");
    vec q = H * I ;

    std::cout << "Error: " << pow(norm(y - A2),2) << "\n";
    std::cout << "Error: " << pow(norm(p - D2),2) << "\n";
    std::cout << "Error: " << pow(norm(q - G2),2) << "\n";
    
    mat M1(1001,2);
    M1.col(0) = A1;
    M1.col(1) = y ;
    M1.save("y.txt",arma_ascii);

     mat M2(1001,2);
    M2.col(0) = D1;
    M2.col(1) = p ;
    M2.save("p.txt",arma_ascii);

     mat M3(1001,2);
    M3.col(0) = G1;
    M3.col(1) = q ;
    M3.save("q.txt",arma_ascii);
    
	return 0;
	
}
