#include <iostream>
using namespace std;
long long a, b, c, tmp;

long long pow(long long b) {
	// 0제곱이면 1
	if (b == 0) return 1;
	// 1제곱이면 그대로 리턴
	if (b == 1) return a%c;

	tmp = pow(b / 2) % c;
	// 분할 정복 사용
	// b가 짝수인 경우 ) a^b = a^(b/2) x a^(b/2)
	// b가 홀수인 경우 ) a^b = a^(b/2) x a^(b/2+1)
	if (b % 2 == 0) return tmp * tmp % c;
	return tmp * tmp % c * a % c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> b >> c;
	cout << pow(b);
	return 0;
}