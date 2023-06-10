#include <iostream>
#include <functional>
#include <regex>

using namespace std;

int ram_a[33];
int reg_m[33];
int reg_a[33];
int reg_q[33];
int number_1[33];
int number_2[33];
int result[33];
int mask[33];

long long a1, a2;

void convert_to_binary(int mask[], long long n) {

	int j = 31;

	while (n > 0) {
		mask[j--] = n % 2;
		n /= 2;
	}
}

void print_array(int a[]) {

	for (int i = 0; i < 32; ++i)
		cout << a[i];

}

void to_additional(int a[]) {

	for (int i = 0; i < 32; ++i)
		a[i] = (a[i] + 1) % 2;

	int j = 31;

	a[j]++;

	while (a[j] == 2) {
		a[j--] %= 2;
		a[j]++;
	}
}

int toDec(int a[]) {

	int result = -(a[0] * pow(2, 32));

	for (int i = 1; i < 32; ++i)
		result += a[i] * pow(2, 31 - i);

	return result;
}

void sum(int a[], int b[], int code) {

	int j = 31, ram = 0;

	while (j >= 0) {
		result[j] = a[j] + b[j] + ram;
		ram = result[j] / 2;
		result[j] %= 2;
		j--;
	}

}

void shift() {

	int ram = reg_q[0];

	for (int i = 0; i < 31; ++i)
		reg_q[i] = reg_q[i + 1];

	reg_q[31] = 0;

	for (int i = 0; i < 31; ++i)
		reg_a[i] = reg_a[i + 1];

	reg_a[31] = ram;
}

void push(int a[], int b[]) {

	if (a[0] == 1)
		for (int i = 0; i < 32; ++i)
			reg_a[i] = 1;

	if (a[0] == 0)
		for (int i = 0; i < 32; ++i)
			reg_a[i] = 0;


	for (int i = 0; i < 32; ++i)
		reg_q[i] = a[i];

	for (int i = 0; i < 32; ++i)
		reg_m[i] = b[i];
}


void substraction(int a[], int b[]) {

	to_additional(b);
	sum(a, b, 2);

	for (int i = 0; i < 32; ++i)
		a[i] = result[i];

}

std::pair<bool, bool> check_zero() {

	int s1 = 0;
	int s2 = 0;

	for (int i = 0; i < 32; ++i) {

		s1 += reg_a[i];
		
		s2 += reg_q[i];
	}

	return std::make_pair(s1 == 0, s2 == 0);

}

void divide(int a[], int b[]) {

	push(a, b);

	if (a2 == 0) {

		std::cout << "\n\nДЕЛЕНИЕ НА НОЛЬ\n";

		exit(0);

	}

	if ((a1 == a2) && (a1 < 0 || a2 < 0)) {
		for (int i = 0; i < 33; ++i)
			reg_q[i] = 1;

		return;
	}

	if (a1 == 0) {

		for (int i = 0; i < 33; ++i)
			reg_q[i] = 0;

		return;
	}

	if (a1 != 0)

	for (int k = 0; k < 32; ++k) {
		shift();

		bool minus = reg_a[0];

		for (int i = 0; i < 32; ++i)
			ram_a[i] = reg_a[i];

		if (reg_m[0] == reg_a[0])
			substraction(reg_a, reg_m);

		else {

			sum(reg_a, reg_m, 1);

			for (int i = 0; i < 32; ++i)
				reg_a[i] = result[i];

		}

		bool new_znak = reg_a[0];

		bool exp = false;

		if (minus == new_znak)
			exp = true;


		auto zero = check_zero();

		if (exp == true || (zero.first == true && zero.second == true))
			reg_q[31] = 1;

		else if (exp == false && (zero.first == false && zero.second == false)) {

			reg_q[31] = 0;

			for (int i = 0; i < 32; ++i)
				reg_a[i] = ram_a[i];

		}
	}

	if (a1 / abs(a1) != a2 / abs(a2)) {

		to_additional(reg_q);

	}

}

template<typename ReturnValue>
ReturnValue CorrectInput(const string& variable_name, const regex& pattern,
	function<ReturnValue(string& input)> converter) {

	string value;

	do {
		cout << "Введите " << variable_name << ":\t";
		cin >> value;
	} while (!regex_match(value, pattern));

	return converter(value);

}


int main() {

	setlocale(LC_ALL, "rus");

	std::cout << '\n';

	a1 = CorrectInput<long long>(std::string("первое число"), std::regex("-?[0-9]*"), [](std::string& s) {return atoi(s.c_str()); });

	a2 = CorrectInput<long long>(std::string("второе число"), std::regex("-?[0-9]*"), [](std::string& s) {return atoi(s.c_str()); });


	convert_to_binary(number_1, abs(a1));
	convert_to_binary(number_2, abs(a2));

	if (a1 < 0 && a2 < 0) {

		int n1[33];
		int n2[33];

		for (int i = 0; i < 33; ++i) {
			
			n1[i] = number_1[i];

			n2[i] = number_2[i];
		}

		if (a1 < 0)
			to_additional(n1);

		if (a2 < 0)
			to_additional(n2);


		std::cout << "\nДвоичная форма хранения в памяти числа " << a1 << ":\t";
		print_array(n1);

		std::cout << "\nДвоичная форма хранения в памяти числа " << a2 << ":\t";
		print_array(n2);

	}

	if (a1 > 0 || a2 > 0) {

		if (a1 < 0)
			to_additional(number_1);

		if (a2 < 0)
			to_additional(number_2);


		std::cout << "\nДвоичная форма хранения в памяти числа " << a1 << ":\t";
		print_array(number_1);

		std::cout << "\nДвоичная форма хранения в памяти числа " << a2 << ":\t";
		print_array(number_2);
	}



	divide(number_1, number_2);

	int res = toDec(reg_q);


	std::cout << "\n\nРезультат деления в двоичном виде:\t";
	print_array(reg_q);

	std::cout << "\nВ десятичном:\t" << res << '\n';

	return 0;
}

