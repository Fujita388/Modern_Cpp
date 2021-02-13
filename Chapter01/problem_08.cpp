#include <iostream>
#include <math.h>


// 格桁の3乗の和を返す
int nar(int num) {
	int sum = 0;
	sum += pow((num/100), 3);
	num -= (num/100) * 100;
	sum += pow((num/10), 3);
	num -= (num/10) * 10;
	sum += pow(num, 3); 
	return sum; 
}	


int main() {
	for (int i = 100; i < 1000; ++i) {
		if (nar(i) == i)
			std::cout << i << " ";
	}
	std::cout << "はアームストロング数です" <<'\n';
	return 0;
}
