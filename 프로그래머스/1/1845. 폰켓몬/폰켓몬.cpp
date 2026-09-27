#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> pokemon{};
    for (auto x : nums)    pokemon.insert(x);
    
    if (pokemon.size() < nums.size()/2) return pokemon.size();
    else    return nums.size()/2;
}