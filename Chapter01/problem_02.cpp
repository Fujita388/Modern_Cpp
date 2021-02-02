#include <iostream>


int min(int a, int b);

 
int main() {
	int num1, num2;  // 入力する値
	int greatest = 0;  // 最大公約数

	std::cout << "二つの正の整数を入力:" << '\n';
	std::cin >> num1 >> num2;

	for (int i = 1; i <= min(num1, num2); ++i) {
		if ((num1 % i == 0) && (num2 % i == 0))
			greatest = i;  
	}
	std::cout << greatest << '\n';
	return 0;
}


// 小さい方の整数を選ぶ
int min(int a, int b) {
	if (a <= b)
		return a;
	else
		return b;
}
