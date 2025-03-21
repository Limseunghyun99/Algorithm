#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
queue<pair<int, int>> air_queue;
queue<pair<int, int>> cheese_queue;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 외부 공기와 맞닿은 치즈를 녹이는 BFS
int bfs_melt_cheese() { 
    while (!air_queue.empty()) {
        int x = air_queue.front().first;
        int y = air_queue.front().second;
        air_queue.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
                if (board[nx][ny] == 0) { // 공기라면 계속 확장
                    air_queue.push({nx, ny});
                } else { // 치즈라면 녹을 후보로 추가
                    cheese_queue.push({nx, ny});
                }
                visited[nx][ny] = true;
            }
        }
    }

    // 치즈를 녹임
    int melted_count = 0;
    while (!cheese_queue.empty()) {
        int x = cheese_queue.front().first;
        int y = cheese_queue.front().second;
        cheese_queue.pop();

        if (board[x][y] == 1) { // 치즈라면 녹임
            board[x][y] = 0;
            melted_count++;

            // 새롭게 공기가 된 부분을 공기 BFS에 추가
            air_queue.push({x, y});
        }
    }

    return melted_count; // 이번 시간에 녹은 치즈 개수 반환
}

// 전체 시뮬레이션 실행
void solve_cheese_problem() {
    int time = 0;
    int last_melt = 0;

    while (true) {
        int melted = bfs_melt_cheese();
        if (melted == 0) break; // 더 이상 녹을 치즈가 없다면 종료
        last_melt = melted;
        time++;
    }

    cout << time << "\n" << last_melt << "\n";
}

// 메인 함수
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    board.assign(N, vector<int>(M));
		visited.assign(N, vector<bool>(M, false));
    // (0,0)에서 BFS를 시작하여 외부 공기 영역 찾기
    air_queue.push({0, 0});
    visited[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    solve_cheese_problem();
    return 0;
}
