#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
long long answer = 0;

long long dfs(int node, vector<long long>& a) {
    visited[node] = true;
    for (int next : graph[node]) {
        if (!visited[next]) {
            long long child_sum = dfs(next, a);
            a[node] += child_sum;
            answer += abs(child_sum); // 이동한 만큼의 cost
        }
    }
    return a[node];
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long total = 0;
    int n = a.size();
    vector<long long> a_ll(a.begin(), a.end()); // long long으로 변환

    for (int i = 0; i < n; ++i) total += a_ll[i];
    if (total != 0) return -1; // 총합이 0이 아니면 불가능

    graph.resize(n);
    visited.assign(n, false);

    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0, a_ll);
    return answer;
}
