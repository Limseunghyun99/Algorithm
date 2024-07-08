#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}


int main()
{
    int num = 0;
    cin >> num;

    vector<pair<int, string>> members;
    int age = 0;
    string name;

    for (int i = 0; i < num; i++) {
        cin >> age >> name;
        members.push_back(make_pair(age, name));
    }
    stable_sort(members.begin(), members.end(), compare);

    for (int idx = 0; idx < num; idx++) {
        cout << members[idx].first << ' '<<members[idx].second<< endl;
    }

    return 0;
}