#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int mul=1, sqr = 0;
    
    for ( auto n : num_list){
        mul *= n;
        sqr += n;
    }
    sqr *= sqr;
    if (mul<sqr){
        answer=1;
    }
    // cout<<mul<<" "<<sqr<<endl;
    
    return answer;
}