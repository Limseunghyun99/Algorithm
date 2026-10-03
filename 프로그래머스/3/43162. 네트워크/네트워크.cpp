#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    // node id
    queue<int> q;
    vector<bool> visited(n, false);
    for (int i=0; i<n;i++){
        if (visited[i]) continue;
        
        answer++;
        visited[i] = true;
        q.push(i);
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            
            for (int j=0;j<n;j++){
                if (computers[cur][j] == 1 && !visited[j]){
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }
    
    
    return answer;
}