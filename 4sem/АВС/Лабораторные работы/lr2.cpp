#include <iostream>
#include <regex>
#include <functional>
#include <string>

typedef long long ll;

int number1[33];
int number2[33];

ll num1_dec;
ll num2_dec;

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


ll to_dec(std::string& s) {

	if (num1_dec < 0 || num2_dec < 0)
		return num1_dec * num2_dec;

	ll res = 0;

	for (std::string::size_type i = 0; i < s.size(); i++) {

		res <<= 1;
		
		res += s[i] - '0'; 
	}

	return res;

}


std::string mul(const std::string& a, const std::string& b) {

	std::string res(a.length() + b.length() - 1, '0');
	
	for (int i = a.length() - 1; i >= 0; i--)
		for (int j = b.length() - 1; j >= 0; j--)
		
			res[i + j] += (a[i] != '0' && b[j] != '0');
		
	
	for (std::string::size_type i = res.length() - 1; i > 0; i--) {

		res[i - 1] += (res[i] - '0') / 2;

		res[i] = (res[i] - '0') % 2 + '0';
	}
	
	while (res[0] > '1') {

		res = "0" + res;
		
		res[0] += (res[1] - '0') / 2;
		
		res[1] = (res[1] - '0') % 2 + '0';
	}
	
	return res;
}

void print_array(int arr[]) {

	for (int i = 0; i < 32; ++i)
		std::cout << arr[i];

}

std::string from_int_to_str(int a[]) {

	std::string res;

	for (int i = 0; i < 32; ++i)
		res.push_back(a[i] ? '1' : '0');

	return res;
}

int main() {

	setlocale(LC_ALL, "rus");

	std::cout << '\n';

	num1_dec = CorrectInput<ll>(std::string("первое число"), std::regex("-?[0-9]*"), [](std::string& s) {return atoi(s.c_str()); });

	num2_dec = CorrectInput<ll>(std::string("второе число"), std::regex("-?[0-9]*"), [](std::string& s) {return atoi(s.c_str()); });

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

	std::string binary_res = mul(from_int_to_str(number1), from_int_to_str(number2));

	binary_res.erase(binary_res.begin(), binary_res.begin() + 30);

	std::cout << "\n\nРезультат умножения в двоичном виде:\t" << binary_res;

	std::cout << "\nВ десятичном:\t" << to_dec(binary_res) << '\n';
	
	return 0;
}