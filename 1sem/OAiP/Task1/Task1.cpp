#include <iostream>
#include <cmath>

int main() {
	double a, b, N;
	int i, n{ 30 };

	i = 1;
	N = 0;

	while(i <= n) {
		if (i % 2 == 0.0) {
			a = i / 2.0;
			b = pow(i, 3.0);
		} else {
		if (i % 2 != 0){
			a = i;
			b = pow(i, 2.0);
		}
		}
		
		N = N + (a - b) * (a - b);
		i++;
	}

	std::cout << std::fixed << "N = " << N << std::endl;
	return 0;
}
