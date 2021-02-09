#include <iostream>


int main() {
	int calc(int num);  // 関数のプロトタイプ
	int input;  // 入力値
	int answer = 0;  // 答え

	std::cout << "正の整数を入力" << '\n';
	std::cin >> input;

	if (input <= 2)
		std::cout << "解なし" << '\n';
	else {
		for (int index = 2; index < input; ++index) {
			if (calc(index) == 1)
				answer = index;
		}
		std::cout << answer << '\n';
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

