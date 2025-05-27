#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // pos[x] = 번호 x가 현재 줄에서 몇 번째인지 저장
    vector<int> pos(N+1);
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        pos[num] = i;
    }

    // 1부터 N까지 연속해서 위치가 증가하는 가장 긴 구간 길이 찾기
    int longest = 1;   // 최소 한 명은 그대로 둘 수 있으므로 초기값 1
    int curr = 1;      // 현재 연속 구간의 길이
    for (int x = 2; x <= N; x++) {
        if (pos[x] > pos[x-1]) {
            // 바로 이전 번호보다 뒤에 있으면 구간 연장
            curr++;
        } else {
            // 끊기면 새 구간 시작
            curr = 1;
        }
        longest = max(longest, curr);
    }

    // 이동시켜야 할 최소 어린이 수 = 전체 수 - 가장 큰 고정 그룹 크기
    cout << (N - longest) << "\n";
    return 0;
}
