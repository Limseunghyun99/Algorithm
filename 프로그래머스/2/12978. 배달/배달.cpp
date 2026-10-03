#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    // graph[a] = {b, cost}
    vector<vector<pair<int,int>>> graph(N+1);
    
    // 인접 도로 정보
    for (auto r : road){
        int a = r[0];
        int b = r[1];
        int c = r[2];
        
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    // 최단거리 저장
    const int INF = 1e9;
    vector<int> dist(N+1, INF);
    dist[1] =0;
    
    // minheap
    priority_queue<
        pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    > pq;
    
    // start
    pq.push({0,1});
    
    while(!pq.empty()){
        auto [curDist, cur] = pq.top();
        pq.pop();
        
        // 더 짧은 경로가 있는 경우
        if (curDist > dist[cur])    continue;
        
        // 연결된 모든 도로 확인
        for (auto [next,cost] : graph[cur]){
            int newDist = curDist + cost;
            
            if (newDist < dist[next]){
                dist[next] = newDist;
                pq.push({newDist, next});   
            }
        }
    }
    
    // 각 노드별 거리 계산은 완료했으니
    // K값 이하의 노드를 추린다
    
    for(int i=0;i<=N;i++){
        if (dist[i]<=K){
            answer++;
        }
    }
    
    return answer;
}