#include <iostream>
#include <cmath>

int main() {

	int A, M, i;
	double B, H, Xi, PI, y;

	i = 0;
	A = 0;
	M = 20;
	PI = 3.1415;
	B = PI / 2;
	H = (B - A) / M;
	Xi = A + i * H;

	for (i = 0; Xi <= B; i++) {

		Xi = A + i * H;
		y = sin(Xi) - cos(Xi);
		std::cout << std::fixed << "y = " << y << std::endl;

	}

	return 0;

}
