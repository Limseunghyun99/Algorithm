#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if(!(cin >> T)) return 0;
    while (T--) {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        // 같은 중심
        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) cout << -1 << '\n'; // 일치: 무한대
            else           cout << 0  << '\n'; // 동심, 반지름 다름: 교점 없음
            continue;
        }

        long long dx = x1 - x2, dy = y1 - y2;
        long long d2 = dx*dx + dy*dy;       // 중심 간 거리의 제곱
        long long rs = r1 + r2;             // 반지름 합
        long long rd = llabs(r1 - r2);      // 반지름 차

        long long rs2 = rs * rs;
        long long rd2 = rd * rd;

        if (d2 > rs2)        cout << 0 << '\n'; // 서로 떨어져 있음
        else if (d2 == rs2)  cout << 1 << '\n'; // 외접
        else if (d2 > rd2)   cout << 2 << '\n'; // 두 점에서 만남
        else if (d2 == rd2)  cout << 1 << '\n'; // 내접
        else                 cout << 0 << '\n'; // 한 원이 다른 원 안, 닿지 않음
    }
    return 0;
}
