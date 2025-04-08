#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Trie {
    Trie* next[2];
    int out;

    Trie() {
        next[0] = next[1] = nullptr;
        out = 0;
    }

    // 패턴 삽입: d는 LOW=+1, HIGH=-1
    void insert(const string& s, int d) {
        Trie* node = this;
        for (char c : s) {
            int idx = c - '0';
            if (!node->next[idx]) node->next[idx] = new Trie();
            node = node->next[idx];
        }
        node->out += d;
    }

    // 실시간 문자열 내 패턴 등장 횟수 계산
    int search_all(const string& s) {
        int total = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            Trie* node = this;
            for (int j = i; j < n; ++j) {
                int idx = s[j] - '0';
                if (!node->next[idx]) break;
                node = node->next[idx];
                total += node->out;
            }
        }
        return total;
    }

    // 메모리 해제
    void clear() {
        for (int i = 0; i < 2; ++i) {
            if (next[i]) {
                next[i]->clear();
                delete next[i];
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int B;
    cin >> B;

    Trie* root = new Trie();
    string s;

    // HIGH 패턴 (d = -1)
    for (int i = 0; i < B; ++i) {
        cin >> s;
        root->insert(s, -1);
    }

    // LOW 패턴 (d = +1)
    for (int i = 0; i < B; ++i) {
        cin >> s;
        root->insert(s, +1);
    }

    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        int score = root->search_all(s);
        if (score == 0) cout << "GOOD\n";
        else if (score > 0) cout << "LOW " << score << '\n';
        else cout << "HIGH " << -score << '\n';
    }

    root->clear();
    delete root;

    return 0;
}
