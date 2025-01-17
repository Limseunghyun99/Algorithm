#include <iostream> // 표준 입출력을 사용하기 위해 포함
using namespace std;

const int MAX = 17; // 문제에서 N의 최대값이 16이므로 충분한 크기로 설정
int N; // 집의 크기
int board[MAX][MAX]; // 집의 상태를 저장하는 배열
int dp[MAX][MAX][3]; // 동적 프로그래밍 배열: (x, y)에서 각 방향으로의 경우의 수 저장

// dx와 dy는 각 방향에 대한 이동을 나타냄. 순서대로 가로, 세로, 대각선
int dx[3] = {0, 1, 1}; // x 좌표 변화량
int dy[3] = {1, 0, 1}; // y 좌표 변화량

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(0); // 입출력 버퍼 비우기 방지

    cin >> N; // 집의 크기 입력

    // 집의 상태 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dp[0][1][0] = 1; // 초기 상태: (0, 1) 위치에 가로 방향으로 파이프 배치

    // 동적 프로그래밍 시작
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 현재 위치가 벽인 경우는 건너뜀
            if (board[i][j] == 1) continue;

            // 가로 방향에서의 경우
            if (j - 1 >= 0) dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];

            // 세로 방향에서의 경우
            if (i - 1 >= 0) dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];

            // 대각선 방향에서의 경우
            if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j] == 0 && board[i][j - 1] == 0) {
                dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }
        }
    }

    // 도착지점 (N-1, N-1)에 도달하는 모든 방향의 경우의 수 합산
    int result = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];

    cout << result << "\n"; // 결과 출력
    return 0; // 프로그램 종료
}
