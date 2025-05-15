#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    // 0: 모름, 1: i가 j를 이김, -1: i가 j에게 짐
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    // 초기 승패 정보 설정
    for (auto& r : results) {
        int win = r[0];
        int lose = r[1];
        graph[win][lose] = 1;
        graph[lose][win] = -1;
    }

    // A 가 B를 이기고 B가 C를 이겼으면
    // A는 C를 이긴건가..? 
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                // i가 k를 이기고 k가 j를 이기면, i는 j를 이김
                if (graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                    graph[j][i] = -1;
                }
                // i가 k에게 졌고, k가 j에게 졌으면, i는 j에게 짐
                else if (graph[i][k] == -1 && graph[k][j] == -1) {
                    graph[i][j] = -1;
                    graph[j][i] = 1;
                }
            }
        }
    }

    // 순위를 매길 수 있는 선수 수 계산
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int count = 0;
        for (int j = 1; j <= n; ++j) {
            if (graph[i][j] != 0) count++;
        }
        if (count == n - 1) answer++;
    }

    return answer;
}
