#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	int cnt = 0;

	vector<string> ans;
	//vector<string> candidates;

	string tmp;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		ans.push_back(tmp);
	}
	sort(ans.begin(), ans.end());

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (binary_search(ans.begin(), ans.end(), tmp)) cnt++;
		else continue;
	}
	cout << cnt << endl;

	return 0;
}