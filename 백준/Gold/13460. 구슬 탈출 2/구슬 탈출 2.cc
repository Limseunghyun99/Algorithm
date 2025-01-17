#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

// rx,ry : red x/y
// bx,by : blue x/y
struct INFO {
    int rx, ry, bx, by, counter;
};

INFO start;
// 가로줄에는 개행 문자가 들어가야 하기때문에 11
char map[10][11];

int bfs() {
    // 상,하
    const int dy[] = {-1, 1, 0, 0};
    // 좌, 우
    const int dx[] = {0,0,-1,1};

    // ry, rx, by, bx
    int visited[10][10][10][10] = {0,};
    queue<INFO> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx];
    int ret = -1;

    while (!q.empty()){
        INFO cur = q.front();   q.pop();
        // 불가능한 경우
        if (cur.counter >10)    break;
        if (map[cur.ry][cur.rx] ==  'O' && map[cur.by][cur.bx] != 'O'){
            ret = cur.counter;
            break;
        }
        // dir -> 상하좌우로 움직이기에 4
        for (int dir=0; dir<4;dir++){
            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;

            // 빨간공 움직임임
            while (1){
                if (map[next_ry][next_rx] !='#' && map[next_ry][next_rx] != 'O'){
                    // 상하, 좌우로 움직이면서 맵 갱신
                    next_ry += dy[dir], next_rx += dx[dir];
                }
                else { 
                    if (map[next_ry][next_rx] =='#'){
                        // 만약에 벽으로 끝났으면 벽에서 멈출 순 없기에 하나 빼줌
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    break;
                }
            }
            // 파란공 움직임임
            while (1){
                if (map[next_by][next_bx] !='#' && map[next_by][next_bx] != 'O'){
                    // 상하, 좌우로 움직이면서 맵 갱신
                    next_by += dy[dir], next_bx += dx[dir];
                }
                else { 
                    if (map[next_by][next_bx] =='#'){
                        // 만약에 벽으로 끝났으면 벽에서 멈출 순 없기에 하나 빼줌
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                    break;
                }
            }
            if (next_ry == next_by && next_rx == next_bx){
                if (map[next_ry][next_rx] != 'O'){
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
                    if (red_dist > blue_dist) {
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    else {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                }
            }
            if (visited[next_ry][next_rx][next_by][next_bx]==0) {
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                INFO next;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.counter = cur.counter +1;
                q.push(next);
            }

        }
    }
    return ret;
}



int main() {
    int n,m;
    scanf("%d %d",&n, &m);

    // map 입력
    for (int i=0; i<n;i++){ scanf("%s", map[i]);    }

    for (int y=0; y<n;y++){
        for (int x=0; x<m; x++){
            if (map[y][x] == 'R'){  start.ry = y, start.rx = x;}
            if (map[y][x] == 'B'){  start.by = y, start.bx = x;}
        }
    }
    start.counter=0;

    int ret = bfs();
    printf("%d",ret);
    return 0;
}