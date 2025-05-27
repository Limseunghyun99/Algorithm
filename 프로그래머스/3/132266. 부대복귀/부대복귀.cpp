#include <string>
#include <vector>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    // 인접 리스트 생성 (1번부터 n번까지)
    vector<vector<int>> adj(n + 1);
    for (auto &r : roads) {
        int u = r[0], v = r[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 거리 배열 초기화 (-1: 미방문)
    vector<int> dist(n + 1, -1);
    queue<int> q;

    // 목적지에서부터 BFS 시작
    dist[destination] = 0;
    q.push(destination);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // 각 출발지에 대한 결과 수집
    vector<int> answer;
    answer.reserve(sources.size());
    for (int s : sources) {
        answer.push_back(dist[s]);
    }
    return answer;
}
