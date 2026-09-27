#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    for (int x:arr){
        answer = lcm(answer,x);
    }
    return answer;
}