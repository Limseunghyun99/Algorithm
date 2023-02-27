#include <iostream>
using namespace std;
 
int T, N;
 
int main() {
    // 입력
    scanf("%d", &T);
    while(T--) {
        int ans[5] = {0,};
 
        scanf("%d", &N);
 
        // ADDH 실행
        ans[0] += N/60;
        N %= 60;
 
        // 조건문
        if(N <= 35) {
            if(N%10 > 5) {
                ans[1] += N/10 + 1;
                ans[4] += 10 - N%10;
            }
            else {
                ans[1] += N/10;
                ans[3] += N%10;
            }
        }
        else {
            ans[0]++;
 
            if(N%10  >= 5) {
                ans[2] += 6 - (N/10+1);
                ans[4] += 10 - N%10;
            }
            else {
                ans[2] += 6 - N/10;
                ans[3] += N%10;
            }
        }
 
        // 출력
        for(int i=0;i<5;i++) printf("%d ", ans[i]);
        printf("\n");
    }
    
}