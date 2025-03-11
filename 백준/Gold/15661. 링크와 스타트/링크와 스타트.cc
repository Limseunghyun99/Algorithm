#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int S[21][21]; // 능력치 배열
int answer = 1e9; // 최솟값을 찾기 위한 큰 값 설정

void solve() {
    int total = (1 << N); // 2^N 개의 부분 집합
    for (int mask = 1; mask < total - 1; mask++) { // 적어도 한 명은 있어야 함
        vector<int> teamA, teamB;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) teamA.push_back(i);
            else teamB.push_back(i);
        }

        // 팀 능력치 계산
        int sumA = 0, sumB = 0;
        for (int i = 0; i < teamA.size(); i++) {
            for (int j = i + 1; j < teamA.size(); j++) {
                sumA += S[teamA[i]][teamA[j]] + S[teamA[j]][teamA[i]];
            }
        }
        for (int i = 0; i < teamB.size(); i++) {
            for (int j = i + 1; j < teamB.size(); j++) {
                sumB += S[teamB[i]][teamB[j]] + S[teamB[j]][teamB[i]];
            }
        }

        answer = min(answer, abs(sumA - sumB));
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }
    
    solve();
    cout << answer << endl;
    return 0;
}
