#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    vector<string> maze(N);
    for (int i = 0; i < N; ++i)
        cin >> maze[i];

    vector<vector<int>> dist(N, vector<int>(M, 1e9));
    deque<pair<int, int>> dq;

    dist[0][0] = 0;
    dq.push_front({0, 0});

    while (!dq.empty()) {
        int x = dq.front().second;
        int y = dq.front().first;
        dq.pop_front();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                int cost = maze[ny][nx] - '0';
                if (dist[ny][nx] > dist[y][x] + cost) {
                    dist[ny][nx] = dist[y][x] + cost;
                    if (cost == 1)
                        dq.push_back({ny, nx});
                    else
                        dq.push_front({ny, nx});
                }
            }
        }
    }

    cout << dist[N - 1][M - 1] << '\n';
    return 0;
}
