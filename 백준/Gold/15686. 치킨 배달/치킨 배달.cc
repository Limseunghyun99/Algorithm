#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
int result = INT_MAX;

// 치킨 거리 계산 함수
int calculateChickenDistance(const vector<int>& selected) {
    int totalDistance = 0;
    for (auto& h : houses) {
        int hx = h.first;
        int hy = h.second;
        int minDist = INT_MAX;

        for (int idx : selected) {
            int cx = chickens[idx].first;
            int cy = chickens[idx].second;
            int dist = abs(hx - cx) + abs(hy - cy);
            minDist = min(minDist, dist);
        }

        totalDistance += minDist;
    }

    return totalDistance;
}

// 조합 만들기 (백트래킹)
void dfs(int start, vector<int>& selected) {
    if (selected.size() == M) {
        int dist = calculateChickenDistance(selected);
        result = min(result, dist);
        return;
    }

    for (int i = start; i < chickens.size(); ++i) {
        selected.push_back(i);
        dfs(i + 1, selected);
        selected.pop_back();
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int val;
            cin >> val;
            if (val == 1) houses.push_back({i, j});
            else if (val == 2) chickens.push_back({i, j});
        }
    }

    vector<int> selected;
    dfs(0, selected);

    cout << result << '\n';
    return 0;
}
