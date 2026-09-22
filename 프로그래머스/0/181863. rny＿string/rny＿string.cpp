#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    for (auto x: rny_string){
        if (x=='m'){
            answer.push_back('r');
            answer.push_back('n');
            continue;
        }
        else{
            answer.push_back(x);
        }
    }
    return answer;
}