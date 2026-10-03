#include <string>
#include <vector>
#include <algorithm>
// #include <numeric>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 0;
    long long right = (long long)*min_element(times.begin(), times.end())*n;

    
    while(left<=right){
        long long mid =left+(right-left)/2;
        long long people = 0;
        for (auto x : times){
            people += mid/x;
        }
        if (people < n){
            left = mid+1;
        }
        else{
            answer = mid;
            right = mid-1;
        }   
    }
    
    return answer;
}