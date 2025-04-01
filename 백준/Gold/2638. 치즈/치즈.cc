#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // for memset

using namespace std;

int N, M;
vector<vector<int>> board;
bool visited[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 외부 공기 영역을 BFS로 탐색
void mark_air() {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 체크
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visited[nx][ny]) continue;

            // 공기 또는 이미 녹은 곳만 탐색
            if (board[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

// 치즈를 녹이는 함수
bool melt_cheese() {
    vector<pair<int, int>> to_melt;

    // 모든 치즈에 대해 외부 공기와 맞닿은 면의 수를 센다
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (board[x][y] != 1) continue;

            int contact = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                if (visited[nx][ny]) contact++; // 외부 공기 접촉
            }

            if (contact >= 2) {
                to_melt.push_back({x, y});
            }
        }
    }

    // 치즈 녹이기
    for (auto [x, y] : to_melt) {
        board[x][y] = 0;
    }

    return !to_melt.empty(); // 녹은 치즈가 있으면 true
}

// 시뮬레이션 함수
void solve_cheese_problem() {
    int time = 0;

    while (true) {
        mark_air(); // 외부 공기 다시 마킹
        if (!melt_cheese()) break; // 치즈가 안 녹으면 종료
        time++;
    }

    cout << time << "\n";
}

// 메인 함수
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    board.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    solve_cheese_problem();
    return 0;
}
