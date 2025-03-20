#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M; // 연구소 크기 (N x M)
vector<vector<int>> lab; // 연구소 지도
vector<pair<int, int>> emptySpaces, virusList; // 빈 칸과 바이러스 위치 저장
int maxSafeZone = 0; // 최대 안전 영역 크기 저장

// 방향 벡터 (상, 하, 좌, 우)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

/**
 * @brief BFS를 사용하여 바이러스 확산을 시뮬레이션
 * @return 확산 후 안전한 영역(0의 개수)
 */
int spreadVirus() {
    queue<pair<int, int>> q;
    vector<vector<int>> tempLab = lab; // 연구소 지도 복사본

    // 모든 바이러스 위치를 큐에 삽입 (동시에 확산 시작)
    for (auto virus : virusList) {
        q.push(virus);
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 네 방향으로 바이러스 확산
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 연구소 내부에 있고, 빈 칸(0)일 경우 확산
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && tempLab[nx][ny] == 0) {
                tempLab[nx][ny] = 2; // 바이러스 확산
                q.push({nx, ny});
            }
        }
    }

    // 안전 영역(0의 개수) 계산
    int safeZone = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tempLab[i][j] == 0) {
                safeZone++;
            }
        }
    }
    return safeZone;
}

/**
 * @brief 벽 3개를 세우는 모든 경우를 탐색하는 DFS (백트래킹)
 * @param count 현재 세운 벽 개수
 * @param index 빈 공간 리스트에서 탐색할 시작 인덱스
 */
void buildWall(int count, int index) {
    if (count == 3) { // 벽을 3개 세운 경우 바이러스 확산 실행
        maxSafeZone = max(maxSafeZone, spreadVirus()); // 최대 안전 영역 갱신
        return;
    }

    // 빈 칸 중에서 벽 3개를 조합하여 세움
    for (int i = index; i < emptySpaces.size(); i++) {
        int x = emptySpaces[i].first;
        int y = emptySpaces[i].second;
        lab[x][y] = 1; // 벽 설치
        buildWall(count + 1, i + 1); // 다음 벽 설치
        lab[x][y] = 0; // 벽 복구 (백트래킹)
    }
}

/**
 * @brief 연구소 초기화 및 벽을 세우는 모든 경우 탐색
 * @return 최대 안전 영역 출력
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 연구소 크기 입력
    cin >> N >> M;
    lab.assign(N, vector<int>(M));

    // 연구소 지도 입력 및 빈 칸, 바이러스 위치 저장
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) {
                emptySpaces.push_back({i, j}); // 빈 칸 저장
            } else if (lab[i][j] == 2) {
                virusList.push_back({i, j}); // 바이러스 위치 저장
            }
        }
    }

    // 벽 3개를 세우는 모든 경우 탐색
    buildWall(0, 0);

    // 최대 안전 영역 출력
    cout << maxSafeZone << "\n";
    return 0;
}
