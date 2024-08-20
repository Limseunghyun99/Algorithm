#include <iostream>
using namespace std;

int map[50][50];
int visited[50][50];
int N, M;

// r방향, c방향
int dir_r[4] = {-1,0,1,0};
int dir_c[4] = { 0,1,0,-1};

void dfs(int r, int c, int d, int sum) {
    for (int i = 0; i < 4; i++) {       //왼쪽부터 반시계방향

        int nd = (d + 3 - i) % 4;
        int nr = r + dir_r[nd];
        int nc = c + dir_c[nd];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M || map[nr][nc] == 1) {  //범위 넘어가거나 벽이면 다음 방향
            continue;
        }

        //a.  아직 청소하지 않은 공간이 존재한다면
        if (visited[nr][nc] == 0 && map[nr][nc] == 0) {
            visited[nr][nc] = 1; //현재 위치 청소
            dfs(nr, nc, nd, sum + 1);
        }

    }


    int backIdx = d + 2 < 4 ? d + 2 : d - 2;
    int backr = r + dir_r[backIdx];
    int backc = c + dir_c[backIdx];
    if (0 <= backr && backr <= N && 0 <= backc && backc <= M) {
        if (map[backr][backc] == 0) {   //뒤쪽 방햑 벽 아니어서 후진할 수 있을 때
            dfs(backr, backc, d, sum);  //한칸 후진
        }
        else {   //뒤쪽 방향 벽이라 후진 못할 때
            cout << sum << endl;
            exit(0);
        }
    }


}


\
int main() {

    int r, c, d;
    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    visited[r][c] = 1;
    dfs(r, c, d, 1);

    return 0;
}