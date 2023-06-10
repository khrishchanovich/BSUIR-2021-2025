#include <iostream>
#include <regex>
#include <functional>
#include <string>

typedef long long ll;

int result[33];

int number1[33];
int number2[33];


template<typename ReturnValue>
ReturnValue CorrectInput(const std::string& variable_name, const std::regex& pattern,
	std::function<ReturnValue(std::string& input)> converter) {

	std::string value;

	do {
		std::cout << "Введите " << variable_name << ":\t";
		std::cin >> value;
	} while (!std::regex_match(value, pattern));

	return converter(value);

}

void to_binary(int mask[], ll n) {
		
	int j = 31;

	while (n > 0) {

		mask[j--] = n % 2;

		n >>= 1;
	}
}

void to_additional(int arr[]) {

	for (int i = 0; i < 32; ++i)
		arr[i] = (arr[i] + 1) % 2;

	int j = 31;

	arr[j]++;

	while (arr[j] == 2) {

		arr[j--] %= 2;

		arr[j]++;

	}		

}

ll to_dec(int arr[]) {

	ll res = -(arr[0] * pow(2, 31));

	for (int i = 1; i < 32; ++i)
		res += arr[i] * pow(2, 31 - i);

	return res;

}

void sum(int a[], int b[], bool issum) {

	int j = 31;
	int ram = 0;

	while (j >= 0) {

		result[j] = a[j] + b[j] + ram;

		ram = result[j] / 2;

		result[j] %= 2;

		--j;

	}

	if ((result[0] != a[0] || result[0] != b[0]) && a[0] == b[0]) {

		std::string op = issum ? " СУММЫ" : " РАЗНОСТИ";

		std::cout << "\n\nПЕРЕПОЛНЕНИЕ" << op;

	}

}

void substraction(int a[], int b[]) {

	to_additional(b);

	sum(a, b, 0);

}

void print_array(int arr[]) {

	for (int i = 0; i < 32; ++i)
		std::cout << arr[i];

}

int main() {
	
	setlocale(LC_ALL, "rus");

	std::cout << '\n';

	ll num1_dec = CorrectInput<ll>(std::string("Первое число"), std::regex("-?[0-9]*"), [](std::string& s) {return atoi(s.c_str()); });

	ll num2_dec = CorrectInput<ll>(std::string("Второе число"), std::regex("-?[0-9]*"), [](std::string& s) {return atoi(s.c_str()); });

	to_binary(number1, abs(num1_dec));
	to_binary(number2, abs(num2_dec));

	if (num1_dec < 0)
		to_additional(number1);

	if (num2_dec < 0)
		to_additional(number2);

	std::cout << "\nДвоичная форма хранения в памяти числа " << num1_dec << ":\t";
	print_array(number1);
	std::cout << "\nДвоичная форма хранения в памяти числа " << num2_dec << ":\t";
	print_array(number2);

	sum(number1, number2, true);

	std::cout << "\n\nРезультат суммы в двоичном виде:\t";
	print_array(result);

	std::cout << "\nВ десятичном:\t" << to_dec(result);

	substraction(number1, number2);

	std::cout << "\n\nРезультат разности в двоичном виде:\t";
	print_array(result);

	std::cout << "\nВ десятичном:\t" << to_dec(result) << '\n';

	return 0;
}