#include <iostream>
#include <algorithm>
using namespace std;

int n, m; // 행, 열
int board[500][500]; // 입력 배열
bool visited[500][500]; // DFS 방문 여부
int dx[4] = {-1, 1, 0, 0}; // 상하좌우 방향 배열
int dy[4] = {0, 0, -1, 1};
int result = 0; // 최대 합 저장 변수

// DFS로 4칸짜리 테트로미노 탐색
void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) { // 블록 4개를 모두 사용했다면
        result = max(result, sum); // 최대값 갱신
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // 배열 범위 안이고 방문하지 않았을 경우
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, depth + 1, sum + board[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}

// "ㅗ", "ㅏ", "ㅜ", "ㅓ" 모양은 DFS로 처리 불가능하므로 따로 처리
void checkExtraShape(int x, int y) {
    // 가능한 "ㅗ" 모양을 중심 기준으로 4가지 경우 확인
    if (x >= 0 && x + 1 < n && y + 2 < m) { // ㅜ
        int temp = board[x][y] + board[x][y+1] + board[x][y+2] + board[x+1][y+1];
        result = max(result, temp);
    }
    if (x - 1 >= 0 && x < n && y + 2 < m) { // ㅗ
        int temp = board[x][y] + board[x][y+1] + board[x][y+2] + board[x-1][y+1];
        result = max(result, temp);
    }
    if (x + 2 < n && y + 1 < m) { // ㅏ
        int temp = board[x][y] + board[x+1][y] + board[x+2][y] + board[x+1][y+1];
        result = max(result, temp);
    }
    if (x + 2 < n && y - 1 >= 0) { // ㅓ
        int temp = board[x][y] + board[x+1][y] + board[x+2][y] + board[x+1][y-1];
        result = max(result, temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m; // 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 모든 좌표에서 시작해서 최대값 탐색
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = true; // 시작점 방문 표시
            dfs(i, j, 1, board[i][j]); // DFS 시작
            visited[i][j] = false;
            checkExtraShape(i, j); // 예외 모양 체크
        }
    }

    cout << result << '\n'; // 결과 출력
    return 0;
}
