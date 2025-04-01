#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, H;
    cin >> N >> H;

    vector<int> stalagmite(H + 2, 0); // 석순 (아래에서 위로)
    vector<int> stalactite(H + 2, 0); // 종유석 (위에서 아래로)

    // 입력
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        if (i % 2 == 0)
            stalagmite[h]++;
        else
            stalactite[h]++;
    }

    // 누적합 계산
    for (int i = H - 1; i >= 1; i--) {
        stalagmite[i] += stalagmite[i + 1];
        stalactite[i] += stalactite[i + 1];
    }

    int min_obstacles = N; // 최악은 전부 부딪히는 경우
    int count = 0;

    // 높이 1부터 H까지 검사
    for (int h = 1; h <= H; h++) {
        int hit = stalagmite[h] + stalactite[H - h + 1];
        if (hit < min_obstacles) {
            min_obstacles = hit;
            count = 1;
        } else if (hit == min_obstacles) {
            count++;
        }
    }

    cout << min_obstacles << ' ' << count << '\n';
    return 0;
}
