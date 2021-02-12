#include <iostream>
#include <cmath>
#include <set>


int main() {
	int div(int num);
	std::set<int> pair;  // 重複しないようにペアを保存

	for (int i = 1; i <= 100000; ++i) {
		if ((div(div(i)) == i) && (div(i) != i)) {
			pair.insert(i);  // 友愛数を追加
			pair.insert(div(i));  // 友愛数を追加
		}
	}
	
	auto itr = pair.begin();  // 最初の要素のイテレータを取得
	for (int j = 0; j < pair.size()/2; ++j) {
		std::cout << "(" << *itr << ", ";
		++itr;
		std::cout << *itr << ")" << '\n';
		++itr;
	}
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
