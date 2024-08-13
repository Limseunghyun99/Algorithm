#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000001
int parent[MAX];
using namespace std;

int find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
	parent[find(y)] = find(x);
}
bool sameparent(int x, int y) {
	if (find(x) ==  find(y) )return true;
	else return false;
}

int main() {
	int node, edge;
	cin >> node >> edge;

	int ans = 0;
	vector<pair<int, pair<int, int>>>v;	// 번호(이름) , pair (연결 정보)

	int from, to, weight;
	for (int i = 0; i < edge; i++) {
		cin >> from >> to >> weight;
		v.push_back({ weight, {from,to} });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= node; i++) parent[i] = i;
	for (int i = 0; i < v.size(); i++) {
		if (!sameparent(v[i].second.first, v[i].second.second)) {
			uni(v[i].second.first, v[i].second.second);
			ans += v[i].first;
		}
	}
	cout << ans;
	return 0;
}