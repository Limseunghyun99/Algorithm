// Headers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// MAX : Maximum number of Team
// S : 2 dimension array that holds the ability score between each team member
// vistied : boolean array to check whether a team member has already been assigned to a team.
// ans : minimum diff between two teams ability 
const int MAX = 20;
int N;
int S[MAX][MAX];
bool visited[MAX];
int ans = 987654321;

// Recursive function that calculate minimum diff between two teams
// cnt : = 현재 팀에 배정된 멤버의 수
// idx : = 새로운 멤버를 배정하기 시작하는 인덱스 위치
// visited 는 dfs활용을 위한 배열
void dfs(int cnt, int idx) {
    if (cnt == N / 2) {
        int start = 0, link = 0;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (visited[i] && visited[j]) {
                    start += S[i][j];
                    start += S[j][i];
                }
                else if (!visited[i] && !visited[j]) {
                    link += S[i][j];
                    link += S[j][i];
                }
            }
        }

        ans = min(ans, abs(start - link));
        return;
    }

    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(cnt + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main() {
    // 꼼수
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // Total Number
    cin >> N;

    // Input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    dfs(0, 0);

    cout << ans << '\n';

    return 0;
}