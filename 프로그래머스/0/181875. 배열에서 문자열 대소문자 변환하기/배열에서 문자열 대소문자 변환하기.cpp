#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    for (int idx=0; idx<strArr.size();idx++){
        for (char &c : strArr[idx]){
            if (idx%2==1){
                c = toupper(c);
            }
            else{
                c = tolower(c);
            }
        }
        answer.push_back(strArr[idx]);
    }
    return answer;
}