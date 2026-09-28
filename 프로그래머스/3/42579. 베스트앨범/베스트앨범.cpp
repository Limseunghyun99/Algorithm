#include <string>
#include <utility> // pair
#include <algorithm> // sort
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // 장르 - {idx, plays}
    unordered_map<string, vector<pair<int,int>>> songs;
    // 장르 - 재생횟수
    unordered_map<string, int> nums;
    
    for (int idx=0; idx<genres.size();idx++){
        songs[genres[idx]].push_back({idx, plays[idx]});
        nums[genres[idx]] += plays[idx];
    }
    // 정렬용 vector
    vector<pair<string,int>> tmp;
    
    for (auto x:nums){
        tmp.push_back({x.first,x.second});
    }
    
    sort(tmp.begin(), tmp.end(),
        [](auto a, auto b){
          return a.second>b.second;
        });
    
    // 장르 - 총 횟수 기준 내림차순상태
    for (auto x:tmp){
        string genre = x.first;
        // 장르 - {idx, 횟수} 를 횟수 기준으로 정렬 (내림차순)
        sort(songs[genre].begin(), songs[genre].end(),
            [](auto a, auto b){
                return a.second>b.second;
            });
        for (int i=0;i<songs[genre].size() && i<2;i++){
            answer.push_back(songs[genre][i].first);
        }
        
    }
    return answer;
}