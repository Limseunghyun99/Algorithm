#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for (int i=0; i<progresses.size();i++){
        int remain = 100 - progresses[i];

        int tmp = remain / speeds[i];

        if (remain % speeds[i] != 0)
            tmp++;
        days.push_back(tmp);
    }
    int idx = 0;

    while (idx < days.size()) {

        int cnt = 1;

        while (idx + cnt < days.size() &&
               days[idx] >= days[idx + cnt]) {
            cnt++;
        }

        answer.push_back(cnt);
        idx += cnt;
    }
    
    
    return answer;
}