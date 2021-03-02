#include <iostream>
#include <cmath>
#include <random>
#include <array>


template<typename E = std::mt19937, typename D = std::uniform_real_distribution<>>
double compute_pi(E& engine, D& dist, const int samples = 100000) {  // 乱数を生成する機能を提供する "エンジン" と、それを目的の値域に整える "ディストリビューション" という 2 つの仕組みを合わせて使う
	auto hit = 0;
	
	for (int i = 0; i < samples; ++i) {
		auto x = dist(engine);
		auto y = dist(engine);

		if (y <= std::sqrt(1 - std::pow(x,2)))
			++hit;
	}
	return 4.0 * hit / samples;
}


int main() {
	// 擬似乱数生成器の状態シーケンスのサイズ分、 シードを用意
	auto seed_data = std::array<int, std::mt19937::state_size> {};
    // 非決定的な乱数でシード列を構築
	std::random_device rd;
	std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
	std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
	// 擬似乱数生成器をシード列で初期化
	auto eng = std::mt19937 {seq};
	auto dist = std::uniform_real_distribution<>{0, 1};

	for (int j = 0; j < 10; ++j) 
		std::cout << compute_pi(eng, dist) << '\n';
	return 0;
}



