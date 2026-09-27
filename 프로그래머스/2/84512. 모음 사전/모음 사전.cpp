#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    string vowel = "AEIOU";
    // 사전 기준으로 AAAAA 보다 AAAA가 앞에 오고 있으니 가중치는 누적으로 계산
    vector<int> weight = {781, 156, 31, 6, 1};
    
    // word의 각 자리 단어의 가중치 합
    for (int i=0;i<word.size();i++){
        int idx = vowel.find(word[i]);
        // idx -> 단어의 가중치
        // weight[i] -> 현재 word에서 몇번째 자리수에 글자가 있는가
        // +1 -> 지금 idx가 0부터 시작
        answer += idx*weight[i]+1;
    }
    return answer;
}