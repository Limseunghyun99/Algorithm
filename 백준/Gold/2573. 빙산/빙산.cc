#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int N, M;
int map[300][300];         // 빙산 높이 저장
int temp[300][300];        // 연산용 임시 배열
bool visited[300][300];    // 방문 체크

// 빙산 덩어리 수 세기 (BFS)
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (!visited[nx][ny] && map[nx][ny] > 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

// 매년 빙산 녹이기
void melt() {
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] > 0) {
                int sea = 0;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (map[ni][nj] == 0)
                        sea++;
                }
                temp[i][j] = max(0, map[i][j] - sea);
            }
        }
    }

    // temp -> map 복사
    memcpy(map, temp, sizeof(map));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    int year = 0;

    while (true) {
        memset(visited, false, sizeof(visited));
        int count = 0;

        // 덩어리 수 세기
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (map[i][j] > 0 && !visited[i][j]) {
                    bfs(i, j);
                    count++;
                }

        if (count == 0) {      // 전부 녹음
            cout << 0;
            return 0;
        }
        if (count >= 2) {      // 분리됨
            cout << year;
            return 0;
        }

        melt();  // 다음 해로
        year++;
    }
}
