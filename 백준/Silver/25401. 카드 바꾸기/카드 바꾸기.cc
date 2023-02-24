#include <stdio.h>
#include <algorithm>
#define NMAX 505
using namespace std;
 
int N;
int arr[NMAX];
 
int diff, val, cnt, ans;
 
int main() {
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%d", &arr[i]);
    
    ans = N-1;
    for(int i=1;i<=N;i++) {
        for(int j=i+1;j<=N;j++) {
            // arr[i] + (j-i)*diff = arr[j]
            if((arr[j]-arr[i])%(j-i) != 0) continue;
            
            diff = (arr[j]-arr[i])/(j-i);
            
            val = arr[i] - (i-1)*diff;
            cnt = 0;
            for(int k=1;k<=N;k++) {
                if(val != arr[k]) cnt++;
                
                val += diff;
            }
            
            ans = min(ans, cnt);
        }
    }
    
    printf("%d", ans);
}
