#include <string>
#include <vector>

using namespace std;

int solution(int number, int n, int m) {
    if ((number%n==0) and (number%m==0)){
        return 1;
    }
    else{
        return 0;
    }
}