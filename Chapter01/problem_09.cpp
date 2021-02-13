#include <iostream>
#include <math.h>


int main() {
	int calc(int num);
	int input;  // 入力値

	std::cout << "正の整数を入力:" << '\n';
	std::cin >> input;

	for (int i = 2; i <= input; ++i) {
		if ((calc(i) == 1) && ((input % i) == 0)) {  // 入力値以下の素数かつ約数
			std::cout << i;  // 素数
			int count = 0;  // 指数部分
			int j = i;
			while ((input % j) == 0) {
				++count;
				j *= j;  // 素数の累乗
			}
			std::cout << " " << count << "乗" << '\n';
			input /= pow(i, count);  // 入力値を素数の累乗でわる
		}
	}
	return 0;
}


// 素数を返す
int calc(int num) {
	int sum = 0;
	for (int i = 2; i < num; ++i) {
		if ((num % i == 0))
			return 0;  // 素数でないなら0を返す
	}
	return 1;  // 素数なら1を返す
}

