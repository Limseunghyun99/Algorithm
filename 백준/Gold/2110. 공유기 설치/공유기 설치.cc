#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 공유기를 최소 거리 dist 이상으로 설치할 수 있는지 확인
bool canInstall(const vector<int>& houses, int C, int dist) {
    int count = 1; // 첫 집에는 무조건 설치
    int lastInstalled = houses[0]; // 마지막으로 설치한 위치

    for (int i = 1; i < houses.size(); i++) {
        if (houses[i] - lastInstalled >= dist) {
            count++; // 공유기 설치
            lastInstalled = houses[i];
        }
    }
    return count >= C;
}

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> houses(N);
    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end()); // 좌표 정렬

    int left = 1; // 최소 거리 (가장 가까운 집이 1칸 차이날 수 있음)
    int right = houses[N - 1] - houses[0]; // 최대 거리
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2; // 현재 시도할 최소 거리
        if (canInstall(houses, C, mid)) {
            answer = mid;       // 가능한 거리면 저장
            left = mid + 1;     // 더 넓은 간격 시도
        } else {
            right = mid - 1;    // 더 좁은 간격 시도
        }
    }

    cout << answer << '\n'; // 가장 넓게 가능한 최소 거리 출력
    return 0;
}
