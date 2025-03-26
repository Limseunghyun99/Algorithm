#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <math.h>
#include <map>
#include <cmath>
#include <utility>
#include <numeric>
#include <functional>


using namespace std;

vector<vector<int>> comb(int n, int k) { // 조합
	vector<vector<int>> result;

	vector<int> chosen(k);

	
	for (int i = 0; i < k; ++i) {
		chosen[i] = i;
	}

	while (true) {
		
		result.push_back(chosen);

		
		int idx = k - 1;
		while (idx >= 0 && chosen[idx] == n - k + idx) {
			idx--;
		}

		if (idx < 0) {
			break;
		}

		chosen[idx]++;
		for (int i = idx + 1; i < k; ++i) {
			chosen[i] = chosen[i - 1] + 1;
		}
	}

	return result;
}

int main() {
	int n, m, house, chi;
	house = 0;
	chi = 0;
	int answer = 0;
	cin >> n >> m;
	vector<pair<int, int>> house_dir; // 집 좌표
	vector<pair<int, int>> chi_dir; // 치킨집 좌표
	vector<vector<int>> hc_dir; // 치킨집 별 집까지 거리
	for (int i = 0; i < n; i++) {
		vector<int> lss;
		for (int j = 0; j < n; j++) {
			int s;
			cin >> s;
			if (s == 1) {
				house++;
				house_dir.push_back(make_pair(i, j));
			}
			else if (s == 2) {
				chi++;
				chi_dir.push_back(make_pair(i, j));
				vector<int> hss;
				hc_dir.push_back(hss); //치킨집 갯수만큼 vector 추가
			}
		}
	}

	int num = 0;
	for (const auto& cd : chi_dir) {
		for (const auto& hd : house_dir) {
			int dir = abs(cd.first - hd.first) + abs(cd.second - hd.second);
			hc_dir[num].push_back(dir); // 치킨집 별로 각 집까지 거리 계산
		}
		num++;
	}

	vector<vector<int>> cc = comb(chi, m);

	int min = 10000000;

	for (const auto& ccc : cc) {
		int all = 0;
		for (int i = 0; i < house; i++) {
			int h_min = 10000;
			for (int j : ccc) {
				if (hc_dir[j][i] < h_min) {
					h_min = hc_dir[j][i]; // 각 집별 치킨 거리 계산
				}
			}
			all += h_min;
		}

		if (all < min) {
			min = all; 
		}
	}

	answer = min;

	cout << answer << endl;

	return 0;
}