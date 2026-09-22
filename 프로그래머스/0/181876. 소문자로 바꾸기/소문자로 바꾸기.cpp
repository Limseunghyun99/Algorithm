#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string myString) {
    for (auto &x:myString){
        x = tolower(x);
    }
    return myString;
}