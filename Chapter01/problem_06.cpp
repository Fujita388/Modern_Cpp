#include <iostream>


int main() {
	int div(int num);
	int input;  // 入力値
	
	std::cout << "正の整数を入力" << '\n';
	std::cin >> input;

	for (int j = 1; j <= input; ++j) {
		if (div(j) > 2*j)
			std::cout << "過剰数は" << j << "、過剰は" << div(j) - 2*j << '\n';
	}
	return 0;
}


// 約数の和を返す
int div(int num) {
	int sum = 0;
	for (int i = 1; i <= num; ++i) {
		if ((num % i) == 0)
			sum += i;
	}
	return sum;
}
