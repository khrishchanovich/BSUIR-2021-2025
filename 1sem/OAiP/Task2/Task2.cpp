#include <iostream>
#include <cmath>

int main() {

	double E = pow(10,-3);
	double dn, sum;
	int n;

	n = 1;
	dn = (1 / pow(2, n)) + (1 / pow(3, n));
	sum = dn;

	do {
		
		dn = (1 / pow(2, n)) + (1 / pow(3, n));
		sum = sum + dn;
		n++; //= n + 1;

	} while (dn < E);

	std::cout << std::fixed << "Sum is equal to " << sum << std::endl;
	return 0;

}
