// Key Idea : [l,r] 구간에 과일이 최대 두종류 이도록 투포인터를 이동시키면서 카운트

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int cnt[10] = {0};     // 과일 종류별 개수 카운트 (1~9)
    int distinct = 0;      // 현재 윈도우 내 서로 다른 과일 종류 수
    int l = 0, maxLen = 0;

    for (int r = 0; r < N; r++) {
        // 오른쪽 확장
        if (cnt[S[r]] == 0) distinct++;
        cnt[S[r]]++;

        // 종류가 2개를 초과하면 왼쪽을 이동해 축소
        while (distinct > 2) {
            cnt[S[l]]--;
            if (cnt[S[l]] == 0) distinct--;
            l++;
        }

        // 최대 길이 갱신
        maxLen = max(maxLen, r - l + 1);
    }

    cout << maxLen << "\n";
    return 0;
}
