#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int idx = 0; idx < phone_book.size() - 1; idx++) {
        if (phone_book[idx + 1].find(phone_book[idx]) == 0) {
            return false;
        }
    }

    return true;
}