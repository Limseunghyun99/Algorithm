#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 방향 벡터: 상, 하, 좌, 우
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};
const char move_dir[4] = {'U', 'D', 'L', 'R'};

// 방향 문자를 인덱스로 변환
int direction(char ch) {
    for (int i = 0; i < 4; ++i)
        if (move_dir[i] == ch) return i;
    return -1;
}

// 특정 문자가 박스를 나타내는지 확인
bool isBox(char ch) {
    return ch == 'b' || ch == 'B';
}

// 특정 문자가 목표 지점을 나타내는지 확인
bool isGoal(char ch) {
    return ch == '+' || ch == 'B' || ch == 'W';
}

// 특정 문자가 플레이어를 나타내는지 확인
bool isPlayer(char ch) {
    return ch == 'w' || ch == 'W';
}

// 특정 문자가 빈 공간을 나타내는지 확인
bool isEmpty(char ch) {
    return ch == '.' || ch == '+';
}

// 게임이 완료되었는지 확인
bool isComplete(const vector<string>& board) {
    for (const auto& row : board)
        for (char ch : row)
            if (ch == 'b') return false;
    return true;
}

int main() {
    int case_num = 1;

    while (true) {
        int R, C;
        cin >> R >> C;
        if (R == 0 && C == 0) break;
        cin.ignore(); // 개행 문자 제거

        vector<string> board(R);
        pair<int, int> player_pos;
        vector<pair<int, int>> goals;

        // 보드 입력 및 플레이어, 목표 지점 위치 파악
        for (int i = 0; i < R; ++i) {
            getline(cin, board[i]);
            for (int j = 0; j < C; ++j) {
                if (isPlayer(board[i][j])) {
                    player_pos = {i, j};
                }
                if (isGoal(board[i][j])) {
                    goals.emplace_back(i, j);
                }
            }
        }

        string moves;
        getline(cin, moves);

        bool game_complete = false;

        for (char cmd : moves) {
            if (game_complete) break;

            int dir = direction(cmd);
            int pr = player_pos.first;
            int pc = player_pos.second;
            int nr = pr + dr[dir];
            int nc = pc + dc[dir];

            if (board[nr][nc] == '#') continue; // 벽이면 이동 불가

            if (isBox(board[nr][nc])) {
                int nnr = nr + dr[dir];
                int nnc = nc + dc[dir];

                if (board[nnr][nnc] == '#' || isBox(board[nnr][nnc])) continue; // 박스를 밀 수 없으면 이동 불가

                // 박스 이동
                board[nnr][nnc] = (board[nnr][nnc] == '+') ? 'B' : 'b';
                board[nr][nc] = (board[nr][nc] == 'B') ? '+' : '.';

                // 모든 박스가 목표 지점에 도달했는지 확인
                if (isComplete(board)) {
                    game_complete = true;
                }
            }

            if (!isBox(board[nr][nc])) {
                // 플레이어 이동
                board[nr][nc] = (board[nr][nc] == '+') ? 'W' : 'w';
                board[pr][pc] = (board[pr][pc] == 'W') ? '+' : '.';
                player_pos = {nr, nc};
            }
        }

        // 결과 출력
        cout << "Game " << case_num++ << ": " << (game_complete ? "complete" : "incomplete") << '\n';
        for (const auto& row : board) {
            cout << row << '\n';
        }
    }

    return 0;
}
