#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 빠르게
    cin.tie(0);

    int M; // 테스트 케이스 개수
    cin >> M;

    while (M--) {
        int n;
        cin >> n; // 수열 길이

        vector<int> result; // 중앙값 저장용

        priority_queue<int> maxHeap; // 왼쪽 (작은 수) 최대 힙
        priority_queue<int, vector<int>, greater<int>> minHeap; // 오른쪽 (큰 수) 최소 힙

        for (int i = 1; i <= n; ++i) {
            int num;
            cin >> num; // 수 입력받기

            // 홀수 번째, 짝수 번째 상관없이 일단 최대 힙에 추가
            if (maxHeap.empty() || num <= maxHeap.top()) {
                maxHeap.push(num);
            } else {
                minHeap.push(num);
            }

            // 힙의 크기 균형 맞추기
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            // 홀수 번째 수를 읽은 경우, 중앙값 저장
            if (i % 2 == 1) {
                result.push_back(maxHeap.top());
            }
        }

        // 출력
        cout << result.size() << '\n'; // 중앙값 개수 출력

        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ' ';
            // 10개 출력할 때마다 줄바꿈
            if ((i + 1) % 10 == 0) {
                cout << '\n';
            }
        }
        // 마지막 줄바꿈 (10개가 안 채워졌을 경우)
        if (result.size() % 10 != 0) {
            cout << '\n';
        }
    }

    return 0;
}
