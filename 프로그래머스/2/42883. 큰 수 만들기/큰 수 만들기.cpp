#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (char x : number) {
        while (!answer.empty() && k > 0 && answer.back() < x) {
            answer.pop_back();
            k--;
        }
        answer.push_back(x);
    }

    // 98765처럼 끝까지 한 번도 제거하지 못한 경우
    if (k > 0) {
        answer.erase(answer.size() - k);
    }
    return answer;
}