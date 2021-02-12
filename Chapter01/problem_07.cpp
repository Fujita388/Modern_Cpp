#include <iostream>
#include <cmath>
#include <vector>


int main() {
	int div(int num);
	std::vector<int> pair;  // 重複しないようにペアを保存

	for (int i = 1; i <= 1000000; ++i) {
		if ((div(div(i)) == i) && (div(i) != i)) {  // 友愛数の条件
			auto itr = std::find(pair.begin(), pair.end(), i);  // 配列内の要素iを走査
			if (itr == pair.end()) {  // 配列内に同じ数字がなかった場合
				pair.push_back(i);  // 友愛数を追加
				pair.push_back(div(i));  // 友愛数を追加
			}
		}
	}

	for (int j = 0; j < pair.size(); j += 2)
		std::cout << "(" << pair[j] << ", " << pair[j+1] << ")" << '\n';

	std::cout << "は友愛数です" << '\n';
	return 0;
}



// 自分以外の約数の和を返す
int div(int num) {
	int sum = 0;
	for (int i = 2; i < std::sqrt(num); ++i) {
		if ((num % i) == 0)
			sum += (i + num/i);
	}
	return sum + 1;
}
