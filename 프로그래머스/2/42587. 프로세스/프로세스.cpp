#include <string>
#include <vector>
#include <queue>
#include <utility>
// #include <unordered_map>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    // index, priority
    // unordered_map<int,int> pq;
    queue<pair<int,int>> pq;
    int target = priorities[location];
    for (int i=0; i<priorities.size();i++){
        pq.push({i,priorities[i]});
    }
    int cnt =1;
    while(!pq.empty()){
        auto tmp = pq.front();
        pq.pop();
        
        bool flag = false;
        for (int i=0;i<pq.size();i++){
            auto x = pq.front();
            pq.pop();
            
            if (tmp.second < x.second){
                flag = true;
            }
            pq.push(x);
        }
        if (flag) {
            pq.push(tmp);
        }
        else{
            if (tmp.first ==location){
                return cnt;
            }
            else{
                cnt++;
            }
        }

    }
    
    
    return answer;
}