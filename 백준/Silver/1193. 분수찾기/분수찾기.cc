#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int cnt = 1;
	while (N > cnt) {
		N -= cnt;
		cnt++;
	}

	if (cnt % 2 == 1)
		cout << cnt + 1 - N << '/' << N << endl;
	else
		cout << N << '/' << cnt + 1 - N << endl;
}