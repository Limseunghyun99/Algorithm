#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    // int answer = 0;
    int min_w = 0;
    int min_h = 0;
    
    int w = 0;
    int h = 0;
    
    for (auto x: sizes){
        w = max(x[0],x[1]);
        h = min(x[0],x[1]);
        
        if (w >min_w) min_w = w;
        if (h > min_h) min_h =h;
    }
    return min_w*min_h;
}