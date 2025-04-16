#include <iostream>
#include <deque>
#include <vector>
using namespace std;

const int MAX = 100001;

int bfs(int start, int goal) {
    vector<int> dist(MAX, -1); // 방문 여부 + 시간 저장
    deque<int> dq;
    
    dist[start] = 0;
    dq.push_back(start);

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        // 목표에 도달했다면 바로 반환
        if (cur == goal) return dist[cur];

        // 1. 순간이동 (0초)
        if (cur * 2 < MAX && dist[cur * 2] == -1) {
            dist[cur * 2] = dist[cur];
            dq.push_front(cur * 2);
        }
        
        // 3. 뒤로 이동 (1초)
        if (cur - 1 >= 0 && dist[cur - 1] == -1) {
            dist[cur - 1] = dist[cur] + 1;
            dq.push_back(cur - 1);
        }

        // 2. 앞으로 이동 (1초)
        if (cur + 1 < MAX && dist[cur + 1] == -1) {
            dist[cur + 1] = dist[cur] + 1;
            dq.push_back(cur + 1);
        }
    }

    return -1; // 이론상 도달 불가능한 경우는 없음
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << bfs(N, K) << endl;
    return 0;
}
