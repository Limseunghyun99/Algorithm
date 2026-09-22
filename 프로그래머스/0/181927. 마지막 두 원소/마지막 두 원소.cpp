#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int a=0, b=0;
    a = num_list[num_list.size()-1];
    b = num_list[num_list.size()-2];
    
    if (a>b){
        num_list.push_back(a-b);
    }
    else{
        num_list.push_back(a*2);
    }    
    return num_list;
}