// Q1. 감시 가능한 영역은 어떻게 확인할 것 인가 -> CCTV의 방향을 설정하여 감시 가능한 영역을 체크
// Q2. CCTV의 방향을 설정하는 방법 -> 백트래킹을 이용하여 모든 CCTV의 방향을 설정
// Q3. CCTV의 방향을 설정한 후, 사각지대를 계산하는 방법 -> CCTV가 감시하지 않는 영역을 카운트 (-1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 방향 벡터 (우, 하, 좌, 상) - 시계 방향으로 설정
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
vector<vector<int>> office;
vector<pair<int, int>> cctvs;
int minBlindSpot = 1e9; // 최소 사각지대 값

// 특정 방향으로 CCTV가 감시하는 영역을 체크하는 함수
void watch(vector<vector<int>>& tempMap, int x, int y, int dir) {
    int nx = x, ny = y;
    while (true) {
        nx += dx[dir];
        ny += dy[dir];
        
        // 경계를 벗어나거나 벽을 만나면 종료
        if (nx < 0 || nx >= M || ny < 0 || ny >= N || tempMap[ny][nx] == 6) return;
        
        // 감시 가능한 공간이라면 감시 영역으로 체크
        if (tempMap[ny][nx] == 0) tempMap[ny][nx] = -1;
    }
}

// 모든 CCTV의 방향을 설정하여 탐색하는 백트래킹 함수
void dfs(int index, vector<vector<int>> tempMap) {
    if (index == cctvs.size()) {
        // 모든 CCTV의 방향을 결정한 경우, 사각지대 계산
        int blindSpot = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tempMap[i][j] == 0) blindSpot++;
            }
        }
        minBlindSpot = min(minBlindSpot, blindSpot);
        return;
    }
    
    // 현재 CCTV 위치
    int y = cctvs[index].first, x = cctvs[index].second;
    int type = office[y][x];
    
    // 각 CCTV의 유형별 가능한 방향
    vector<vector<int>> directions = {
        {},
        {0}, {0, 2}, {0, 1}, {0, 2, 3}, {0, 1, 2, 3}
    };
    
    for (int rotation = 0; rotation < 4; rotation++) { // 4방향 회전 고려
        vector<vector<int>> newMap = tempMap;
        
        for (int dir : directions[type]) {
            watch(newMap, x, y, (dir + rotation) % 4);
        }
        
        dfs(index + 1, newMap);
    }
}

int main() {
    cin >> N >> M;
    office.resize(N, vector<int>(M));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5) {
                cctvs.emplace_back(i, j);
            }
        }
    }
    
    dfs(0, office);
    
    cout << minBlindSpot << endl;
    return 0;
}
