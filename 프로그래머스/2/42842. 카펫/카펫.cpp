#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow; 
    for (int row=total; row>=3;row--){
        if (total%row != 0) continue;
        
        int col = total/row;
        if ((row-2)*(col-2)==yellow)    return {row,col};
    }
    return {};
}