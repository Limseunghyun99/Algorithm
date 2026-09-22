#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    sort(num_list.begin(), num_list.end());
    // for (auto x: num_list){
    //     cout<<x<<endl;
    // }
    vector<int> answer (num_list.begin(), num_list.begin()+5);
    return answer;
}