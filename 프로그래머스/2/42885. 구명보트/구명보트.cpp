#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int tmp=0;
    int left = 0;
    int right = people.size()-1;
    sort(people.begin(), people.end());
    while(left<=right){
        if (people[left]+people[right]<=limit){
            left++;
        }
        right--;
        answer++;
    }
    return answer;
}