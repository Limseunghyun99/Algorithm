#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N); // 각 카드의 목표 플레이어
    vector<int> S(N); // 섞는 패턴

    for (int i = 0; i < N; ++i) cin >> P[i];
    for (int i = 0; i < N; ++i) cin >> S[i];

    vector<int> cards(N); // 현재 카드 상태 (카드 번호)
    for (int i = 0; i < N; ++i) cards[i] = i;

    int shuffleCount = 0;
    vector<int> original = cards; // 원래 상태 저장 (무한 반복 방지)

    while (true) {
        // 현재 카드가 각 플레이어의 조건을 만족하는지 검사
        bool matched = true;
        for (int i = 0; i < N; ++i) {
            if (P[cards[i]] != i % 3) { // 카드 cards[i]가 i번 자리에 있을 때
                matched = false;
                break;
            }
        }
        if (matched) {
            cout << shuffleCount << '\n';
            return 0;
        }

        // 섞기 진행
        vector<int> next(N);
        for (int i = 0; i < N; ++i) {
            next[S[i]] = cards[i]; // 현재 cards[i]를 S[i]번 위치로 이동
        }

        cards = next;
        shuffleCount++;

        // 다시 원래 상태로 돌아오면 불가능하다는 뜻 (무한 루프 방지)
        if (cards == original) {
            cout << -1 << '\n';
            return 0;
        }
    }
}
