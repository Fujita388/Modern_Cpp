#include <iostream>
#include <algorithm>


bool evaluate(std::string_view line) {  // 文字列のコピーを持つのではなく参照をして、参照先の文字列を加工して扱う
	if ((line.length() == 10) && (std::all_of(std::begin(line), std::end(line), isdigit))) {  // 範囲内の要素のすべてが指定された条件を満たすか調べる。全てが条件を満たす場合にtrue になる。
		auto weight = 10;
		auto sum = 0;
		for (auto i = 0; i < 10; ++i) {
			int num = line[i] - '0';  // charをintに変換
			sum += num * weight;
			--weight;
		}
		if ((sum % 11) == 0)
			return true;
		else
			return false;
	}
	else
		return false;
}


int main() {
	
	std::string line;
	std::cout << "数列: " << '\n';
	std::cin >> line;

	std::cout << "valid: " << evaluate(line) << '\n';
	return 0;
}
