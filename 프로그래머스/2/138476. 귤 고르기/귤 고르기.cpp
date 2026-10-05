#include <string>
#include <vector>
#include <algorithm>
// #include <utility>
// #include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int cnt = 0;
    int maxSize = *max_element(tangerine.begin(), tangerine.end());
    vector<int> sizes(maxSize + 1, 0);
    for (int i=0;i<tangerine.size();i++){
        sizes[tangerine[i]]++;
    }
    sort(sizes.begin(), sizes.end(),greater<>());
    
    // for (int i=0; i<sizes.size();i++){
        // pq.push(make_pair(i,sizes[i]));
        // pq.push(sizes[i]);
    // }
    for (int i=0; i<sizes.size();i++){
        if (answer >= k)  return cnt;
        else    {
            answer += sizes[i];
            cnt++;
        }
    }
    
    return cnt;
}