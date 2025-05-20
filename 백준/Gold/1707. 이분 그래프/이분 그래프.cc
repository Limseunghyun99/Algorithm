#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, const vector<vector<int>>& adj) {
    vector<int> color(V + 1, 0);           // 0: 미방문, 1 / -1: 색
    queue<int> q;

    for (int start = 1; start <= V; ++start) {
        if (color[start] != 0) continue;   // 이미 방문한 연결 요소
        color[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                if (color[nxt] == 0) {                 // 미방문 → 반대 색
                    color[nxt] = -color[cur];
                    q.push(nxt);
                } else if (color[nxt] == color[cur]) {  // 같은 색 충돌
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int V, E; cin >> V >> E;
        vector<vector<int>> adj(V + 1);
        for (int i = 0; i < E; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << (isBipartite(V, adj) ? "YES\n" : "NO\n");
    }
    return 0;
}
