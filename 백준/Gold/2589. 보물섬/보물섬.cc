#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int R, C;
vector<string> grid;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int bfs(int sx, int sy) {
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pii> q;
    dist[sx][sy] = 0;
    q.emplace(sx, sy);
    int maxd = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx<0 || nx>=R || ny<0 || ny>=C) continue;
            if (grid[nx][ny]=='L' && dist[nx][ny]==-1) {
                dist[nx][ny] = dist[x][y] + 1;
                maxd = max(maxd, dist[nx][ny]);
                q.emplace(nx, ny);
            }
        }
    }
    return maxd;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    grid.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }

    int answer = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'L') {
                answer = max(answer, bfs(i, j));
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
