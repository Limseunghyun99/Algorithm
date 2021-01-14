#include <iostream>  
using namespace std;
int array[2002], dp[2002][2002], n, m, s, e; 
int main() { 
    cin >> n; // 배열 길이
    for(int i = 0; i < n; i++)cin >> array[i]; //배열 입력
    for(int i = 0; i < n; i++)dp[i][i] = 1; //배열 길이가 1이면 팰린드롬
    for(int i = 0; i < n - 1; i++){
        if(array[i] == array[i + 1])dp[i][i + 1] = 1; //배열 길이가 2일때 팰린드롬인지 확인
    } 

    for(int len = 3; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            if(array[i] == array[j] && dp[i + 1][j - 1])dp[i][j] = 1; 
        }
    } 
    cin >> m;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s-1][e-1]);
        //cin >> s >> e; 
        //cout << dp[s - 1][e - 1] << '\n';
    }
    return 0;
}
