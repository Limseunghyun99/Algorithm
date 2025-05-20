#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int cnt = 0;   // 연속된 "IOI" 패턴 개수
    int ans = 0;   // 최종 정답
    int i = 1;     // 문자열 S[1]부터 S[M-2]까지 체크

    while (i < M - 1) {
        // "IOI" 한 세트 발견 시
        if (S[i] == 'O' && S[i-1] == 'I' && S[i+1] == 'I') {
            cnt++;
            if (cnt >= N) 
                ans++;
            i += 2;   // 다음 'I' 위치로 점프
        } else {
            cnt = 0;  // 연속 패턴 끊김
            i++;
        }
    }

    cout << ans << "\n";
    return 0;
}
