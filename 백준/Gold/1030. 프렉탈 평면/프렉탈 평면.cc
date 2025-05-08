#include <iostream>
#include <cmath>
using namespace std;

int s, N, K, R1, R2, C1, C2;

// 주어진 좌표가 검은 영역인지 재귀적으로 판별
int isBlack(int x, int y, int level) {
    if (level == 0) return 0;

    int len = pow(N, level);          // 전체 길이
    int unit = len / N;               // 한 칸 크기
    int nx = x / unit;                // 현재 좌표의 블록 위치
    int ny = y / unit;

    int margin = (N - K) / 2;

    // 현재 단계에서 검은 부분이면
    if (nx >= margin && nx < N - margin && ny >= margin && ny < N - margin)
        return 1;
    else
        return isBlack(x % unit, y % unit, level - 1); // 상위 블록에서 확인
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

    for (int i = R1; i <= R2; i++) {
        for (int j = C1; j <= C2; j++) {
            cout << isBlack(i, j, s);
        }
        cout << '\n';
    }

    return 0;
}
