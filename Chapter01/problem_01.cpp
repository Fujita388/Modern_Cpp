#include <iostream>


int main() {
	int upper;  // 上限
	int sum = 0;  // 合計

	std::cout << "上限(正の整数)を指定:" << '\n';
	std::cin >> upper;
	
	for (int i = 1; i <= upper; ++i) {
		//std::cout << i << '\n';
		if ((i % 3 == 0) || (i % 5 == 0))
			sum += i;
	}
	std::cout << sum << '\n';
	return 0;
}


