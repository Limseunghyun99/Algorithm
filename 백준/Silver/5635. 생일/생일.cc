#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const pair<string, int>& p1, const pair<string, int>& p2) {
    return p1.second < p2.second;
}

int main() {
    vector<pair<string, int>> v;

    int num = 0;

    string name;
    int day = 0;
    int month = 0;
    int year = 0;

    int days = 0;

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> name >> day >> month >> year;
        // 일수 계산, 윤년과 실제 월 일수 고려하지 않은 단순 계산
        days = day + (month * 30) + ((year - 1900) * 365);
        // cout << "Days of " << name << days << endl; // 불필요한 출력 제거
        v.push_back(make_pair(name, days));
    }

    // 비교 함수 cmp를 사용하여 정렬
    sort(v.begin(), v.end(), cmp);

    // 첫 번째 원소와 마지막 원소의 이름 출력
    cout << v[v.size() - 1].first<< " " << v[0].first  << endl;

    return 0;
}
