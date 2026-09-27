#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    // 전체 - 뺏긴 사람 = 일단 수업 참여 가능한 애드 
    int answer = n - lost.size();
    int idx =0;
    // 도난당했지만 여벌도 있는 학생 처리
    for (int l = 0; l < lost.size(); l++) {
        for (int r = 0; r < reserve.size(); r++) {
            if (lost[l] == reserve[r]) {
                answer++;
                lost[l] = -1;
                reserve[r] = -1;
                break;
            }
        }
    }

    
    
    for (int l = 0; l < lost.size(); l++) {
    for (int r = 0; r < reserve.size(); r++) {
        if (lost[l] - 1 == reserve[r] ||
            lost[l] + 1 == reserve[r]) {
            answer++;
            // 이 학생은 이미 빌려줬으므로 재사용 방지
            reserve[r] = -1;
            break;
        }
    }
}
    return answer;
}