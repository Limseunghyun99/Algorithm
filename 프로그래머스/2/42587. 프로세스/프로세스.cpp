#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {

    // {우선순위, 원래 위치}
    queue<pair<int,int>> q;

    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }

    // 실행되어야 하는 우선순위 순서
    vector<int> order = priorities;
    sort(order.begin(), order.end(), greater<int>());

    int cnt = 0;

    while (!q.empty()) {

        auto cur = q.front();
        q.pop();

        // 현재 가장 높은 우선순위라면 실행
        if (cur.first == order[cnt]) {
            cnt++;
            if (cur.second == location) {
                return cnt;
            }
        }
        // 더 높은 우선순위가 남아있다면 뒤로
        else {
            q.push(cur);
        }
    }

    return 0;
}