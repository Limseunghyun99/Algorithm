#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> tmp;
    for (int i=0; i<elements.size();i++){
        int result=0;
        for (int j=i; j<i+elements.size();j++){
            int idx = j % elements.size();
            result += elements[idx];
            tmp.insert(result);
        }
    }
    
    return tmp.size();
}