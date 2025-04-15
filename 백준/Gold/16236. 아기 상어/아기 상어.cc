#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> sea;
int dx[] = {-1, 0, 0, 1}; // 위, 좌, 우, 아래
int dy[] = {0, -1, 1, 0};

struct Shark {
    int x, y, size = 2, eaten = 0;
};

int bfs(Shark &shark) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(N, vector<int>(N, -1));
    q.push({shark.x, shark.y});
    dist[shark.x][shark.y] = 0;

    vector<tuple<int, int, int>> fishList; // (거리, x, y)

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (dist[nx][ny] != -1 || sea[nx][ny] > shark.size) continue;

            dist[nx][ny] = dist[x][y] + 1;

            if (sea[nx][ny] > 0 && sea[nx][ny] < shark.size) {
                fishList.push_back({dist[nx][ny], nx, ny});
            }

            q.push({nx, ny});
        }
    }

    if (fishList.empty()) return 0;

    sort(fishList.begin(), fishList.end());
    auto [d, fx, fy] = fishList[0];

    shark.x = fx;
    shark.y = fy;
    shark.eaten++;
    if (shark.eaten == shark.size) {
        shark.size++;
        shark.eaten = 0;
    }

    sea[fx][fy] = 0;
    return d;
}

int main() {
    cin >> N;
    sea.assign(N, vector<int>(N));
    Shark shark;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> sea[i][j];
            if (sea[i][j] == 9) {
                shark.x = i;
                shark.y = j;
                sea[i][j] = 0;
            }
        }

    int time = 0;
    while (true) {
        int t = bfs(shark);
        if (t == 0) break;
        time += t;
    }

    cout << time << endl;
    return 0;
}
