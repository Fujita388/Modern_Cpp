#include <iostream>
#include <vector>


std::pair<unsigned long long, long> collatz(int limit) {
	std::vector<int> array(limit+1, 0);  // コラッツ数列の配列を初期化
	long longest_length = 1;  // 最長の数列の長さ
	unsigned long long number = 0;  // コラッツ数
	array[1] = 1;

	for (unsigned long long i = 2; i <= limit; ++i) {
		long length = 0;  // 数列の長さ
		unsigned long long n = i;  
		while (n != 1 && n >= i) {
			if ((n % 2) == 0) 
				n = n / 2;
			else 
				n = n * 3 + 1;
			++length;
		}
		array[i] = length + array[n];  // n <= iの時、答えは既に計算済み
		if (array[i] > longest_length) {  // コラッツ数を更新
			longest_length = array[i];
			number = i;
		}
	}
	return std::make_pair(number, longest_length);
}


int main() {	
	auto result = collatz(100000000);
	std::cout << "最長コラッツ数: " << result.first << " 、数列の長さ: " << result.second << '\n';
	return 0;
}
