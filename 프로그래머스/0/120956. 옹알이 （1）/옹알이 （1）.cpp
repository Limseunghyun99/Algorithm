#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSpeakable(const string& word, const vector<string>& speakables) {
    int i = 0;
    string prev = "";

    while (i < word.size()) {
        bool matched = false;

        for (const string& s : speakables) {
            if (word.substr(i, s.size()) == s && s != prev) {
                matched = true;
                prev = s;
                i += s.size();
                break;
            }
        }

        if (!matched) return false; // 어떤 단어도 매칭되지 않으면 발음 불가
    }

    return true;
}

int solution(vector<string> babbling) {
    vector<string> speakables = {"aya", "ye", "woo", "ma"};
    int count = 0;

    for (const string& word : babbling) {
        if (isSpeakable(word, speakables)) {
            count++;
        }
    }

    return count;
}
