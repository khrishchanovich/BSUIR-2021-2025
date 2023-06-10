
#include <iostream>

int main() {

	int i{ 1 }, n;
	double S{};

	std::cout << "n = ";
	std::cin >> n;

	//1

	while (i <= n) {

		if (i % 2 == 0) {

			S = S + i;

		} 

		i++;
	}

	std::cout << "S = " << S << std::endl;
	
	//2

	if (i <= n) {
		if (i % 2 == 0) {

			S = S + i;
			i++;
		}
	}

	std::cout << "S = " << S << std::endl;

	return 0;

}