#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto x : commands){
    vector<int> tmp(array.begin() + x[0] - 1,
                array.begin() + x[1]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[x[2]-1]);
    }
    return answer;
}