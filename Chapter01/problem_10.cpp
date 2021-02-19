#include <iostream>
#include <bitset>


int main() {
	unsigned int encode(unsigned int binary); 
	unsigned int decode(unsigned int gray); 
	
	std::cout << "2進数表現 " << "グレイコード " << "グレイコードの復号値" << '\n';
	for (int j = 0; j < 32; ++j) {
		std::cout << j << "   ";
		std::cout << std::bitset<5> (j) << "   ";
		std::cout << std::bitset<5> (encode(j)) << "   ";  
		std::cout << std::bitset<5> (decode(encode(j))) << '\n';  // 引数(グレイコード)を10進数として与える 
	}
	return 0;
}


// グレイコードに変換
unsigned int encode(unsigned int binary) {
	return binary ^ (binary >> 1);  // 10進数で返す
}


// グレイコードを復号
unsigned int decode(unsigned int gray) {
	for (unsigned int i = 32; i > 1; i >>= 1) {
		if (gray & i) {
			gray ^= (i >> 1); 
		}
	}
	return gray;  // 10進数で返す
}
