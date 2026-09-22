#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 2*a*b;
    int tmp = stoi(to_string(a)+to_string(b));
    if (answer>tmp){
        return answer;
    }
    else{
        return tmp;
    }
}