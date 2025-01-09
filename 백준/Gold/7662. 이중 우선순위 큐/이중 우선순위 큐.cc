#include <iostream>
#include <set>

using namespace std;

int main() {
    int t; // 테스트 케이스 개수
    cin >> t;

    for (int test = 0; test < t; test++) {
        int k; // 연산의 개수
        cin >> k;

        multiset<int> q; // 중복 허용 우선순위 큐

        for (int i = 0; i < k; i++) {
            char oper;
            int n;
            cin >> oper >> n;

            if (oper == 'I') {
                // 삽입 연산
                q.insert(n);
            } 
            else if (oper == 'D') {
                if (!q.empty()) {
                    if (n == 1) {
                        // 최댓값 삭제
                        auto maxIt = prev(q.end());
                        q.erase(maxIt);
                    } else if (n == -1) {
                        // 최솟값 삭제
                        auto minIt = q.begin();
                        q.erase(minIt);
                    }
                }
            }
        }

        // 결과 출력
        if (q.empty()) {
            cout << "EMPTY" << endl;
        } 
        else {
            auto maxVal = *prev(q.end());
            auto minVal = *q.begin();
            cout << maxVal << " " << minVal << endl;
        }
    }

    return 0;
}
