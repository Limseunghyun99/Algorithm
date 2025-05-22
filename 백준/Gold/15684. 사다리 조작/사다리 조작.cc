#include <iostream>
using namespace std;

const int MAX = 31;
int N, M, H;
int ladder[MAX][11]; // ladder[y][x]는 x와 x+1 사이에 가로선이 있는지
int answer = 4; // 최대 3개까지 가능, 초기값은 불가능한 값

// 사다리를 타서 i번 세로선이 i로 끝나는지 확인
bool check() {
    for (int i = 1; i <= N; ++i) {
        int x = i;
        for (int y = 1; y <= H; ++y) {
            if (ladder[y][x]) x++;
            else if (ladder[y][x - 1]) x--;
        }
        if (x != i) return false;
    }
    return true;
}

// 백트래킹: count는 현재까지 놓은 가로선 개수, y,x는 탐색 시작 위치
void dfs(int count, int y, int x) {
    if (count >= answer) return; // 가지치기
    if (check()) {
        answer = count;
        return;
    }
    if (count == 3) return; // 최대 3개까지만 가능

    for (int i = y; i <= H; ++i) {
        for (int j = (i == y ? x : 1); j < N; ++j) {
            // 현재 위치, 좌우에 가로선이 없어야만 설치 가능
            if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1]) continue;
            ladder[i][j] = 1;
            dfs(count + 1, i, j);
            ladder[i][j] = 0; // 백트래킹
        }
    }
}

int main() {
    cin >> N >> M >> H;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1; // a번째 줄에서 b와 b+1 사이에 가로선
    }

    dfs(0, 1, 1);

    cout << (answer > 3 ? -1 : answer) << "\n";
    return 0;
}
