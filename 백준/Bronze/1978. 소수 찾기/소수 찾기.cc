#include <iostream>
using namespace std;

int main() {
	int N, num, decimal=0, count=0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;

		if (num == 2) {		// 2는 소수
			decimal++;
		}
		else {
			if (num == 1) {		// 1은 소수가 아님!
				count++;
			}
			for (int j = 2; j < num; j++) {			
				if (num % j == 0) {					
					count++;
				}
			}
			if (count == 0) {	// count == 0인 소수만 decimal++
				decimal++;
			}
			count = 0;			//  count = 0으로 다시 초기화하기
		}
	}

	cout << decimal;			// decimal 출력

	return 0;
}