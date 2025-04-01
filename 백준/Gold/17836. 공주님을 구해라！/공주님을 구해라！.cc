#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M, T;
int board[101][101]; // 성의 지도
bool visited[101][101][2]; // [x][y][검 획득 여부] 방문 여부

int dx[4] = {1, -1, 0, 0}; // 방향벡터: 아래, 위, 오른쪽, 왼쪽
int dy[4] = {0, 0, 1, -1};

int bfs() {
    queue<tuple<int, int, int, int>> q; // (x, y, time, has_gram)
    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        auto [x, y, t, has_gram] = q.front(); q.pop();

        // 시간 초과 검사
        if (t > T) continue;

        // 공주님에게 도착!
        if (x == N - 1 && y == M - 1) return t;

        // 4방향 탐색
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 범위 벗어남
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 이미 방문한 위치
            if (visited[nx][ny][has_gram]) continue;

            // 검이 없을 경우
            if (has_gram == 0) {
                if (board[nx][ny] == 0) { // 이동 가능
                    visited[nx][ny][0] = true;
                    q.push({nx, ny, t + 1, 0});
                } else if (board[nx][ny] == 2) { // 검 획득
                    visited[nx][ny][1] = true;
                    q.push({nx, ny, t + 1, 1});
                }
                // 벽이면 아무것도 안 함
            }
            // 검을 가지고 있는 경우: 벽도 지나갈 수 있음
            else {
                visited[nx][ny][1] = true;
                q.push({nx, ny, t + 1, 1});
            }
        }
    }
    return -1; // 공주님을 구하지 못함
}

int main() {
    cin >> N >> M >> T;

    // 지도 입력
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    int result = bfs();

    if (result != -1 && result <= T) cout << result << '\n';
    else cout << "Fail\n";

    return 0;
}
