#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int K;
    cin >> N >> K;

    // 이미 목표 이하라면 구매 불필요
    if (__builtin_popcountll(N) <= K) {
        cout << 0;
        return 0;
    }

    long long added = 0;
    // popcount(N) > K인 동안 가장 작은 1비트를 구매해서 합치기
    while (__builtin_popcountll(N) > K) {
        long long lsb = N & -N;  // 최하위 1비트
        added += lsb;            // 그만큼 물병 구매
        N += lsb;                // 구매 후 합치기 효과 반영
    }

    cout << added;
    return 0;
}
