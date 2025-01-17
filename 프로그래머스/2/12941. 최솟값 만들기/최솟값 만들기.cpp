#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(),A.end());
    sort(B.rbegin(),B.rend());
    
    for (int idx=0; idx<A.size();idx++){
        answer += A[idx]*B[idx];
    }
    
    return answer;
}