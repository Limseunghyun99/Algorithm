#include<vector>
#include <queue>
#include <utility>
using namespace std;

vector<int> ud = {1,0,-1,0};
vector<int> lr = {0,1,0,-1};
int answer = 0;


int solution(vector<vector<int> > maps)
{
    int row = maps.size();
    int col = maps[0].size();
    
    vector<vector<int>> graph(
    row,
    vector<int>(col,-1)
    );

    queue<pair<int,int>> q;
    
    // 해당 위치까지 오는데 필요한 비용
    graph[0][0] = 1;
    q.push({0,0});
    // visited[0][0] = true;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        
        for (int i=0; i<4; i++){
            int nx = x+ud[i];
            int ny = y+lr[i];
        
            if (nx <0 || nx >=row || ny <0 || ny >=col){
                continue;
            }
            else if (maps[nx][ny] == 0 || graph[nx][ny] != -1){
                continue;
            }
            else{
                graph[nx][ny] = graph[x][y]+1;
                // visited[nx][ny] = true;
                q.push({nx,ny});
            }
        
        }
        
    }
    
    
    return graph[row-1][col-1];
}