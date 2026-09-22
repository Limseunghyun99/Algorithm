#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string myString, string pat) {
    for (auto &c : myString){
        c = toupper(c);
    }
    for (auto &c : pat){
        c = toupper(c);
    }
    if (myString.find(pat) != string::npos){
        return 1;
    }
    else{
        return 0;
    }
}