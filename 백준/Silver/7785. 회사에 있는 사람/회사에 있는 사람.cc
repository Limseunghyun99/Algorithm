#include <iostream>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    set<string> working;

    string name, action;
    for (int i = 0; i < num; i++) {
        cin >> name >> action;
        if (action == "enter") {
            working.insert(name);
        }
        else {
            working.erase(name);
        }
    }

    //set<string, greater<>> sorted_working(working.begin(), working.end());

    for (auto it = working.rbegin(); it != working.rend(); it++) {
        cout << *it << '\n';
    }

    return 0;
}
