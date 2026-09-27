#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    // sort(dungeons.begin(), dungeons.end(),[](const auto &a, const auto &b){ return a[0]>b[0]})
    vector<int> order{};
    for (int i=0;i<dungeons.size();i++) order.push_back(i);
    do{
        int fatigue = k;
        int count=0;
        for (int idx : order){
            if(dungeons[idx][0] <= fatigue){
                fatigue -= dungeons[idx][1];
                count++;
                }
        }
        answer = max(answer,count);
    }
    while(next_permutation(order.begin(), order.end()));
    return answer;
}