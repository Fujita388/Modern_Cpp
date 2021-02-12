#include <iostream>


int main() {
	int calc(int num);
	int input;  // 入力値

	std::cout << "正の整数を入力" << '\n';
	std::cin >> input;
	
	if (input <= 6)
		std::cout << "解なし" << '\n';

	else {
		for (int index = 2; index <= (input-6); ++index) {
			if ((calc(index) == 1) && (calc(index+6) == 1))
				std::cout << "(" <<index << ", " << index + 6 << ") "; 
		}
		std::cout << "はセクシー素数です" << '\n';
	}
	return 0;
}


// 素数判定
int calc(int num) {
	for (int i = 2; i < num; ++i) {
		if ((num % i) == 0)
			return 0;  // 素数でないなら0を返す
	}
	return 1;  // 素数なら1を返す
}
