#include<iostream>
using namespace std;
#define MIN -9999999

int main()
{
    int n,m;
    int map[1005][1005];
    int dp[1005][1005][2];
    scanf("%d %d", &n,&m);
    for(int i=0; i<=n+1; i++){ //dp 배열 초기화
        for(int j=0; j<=m+1;j++){
            dp[i][j][0] = MIN;
            dp[i][j][1] = MIN;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m;j++){ //입력
            scanf("%d", &map[i][j]);
        }
    }
    dp[1][1][0] =map[1][1]; //출발점 값 입력
    for(int j=2; j<=m;j++){
        dp[1][j][0] = map[1][j] + dp [1][j-1][0]; // 첫줄값 입력
    }
    for (int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){ // 왼쪽부터 오른쪽으로
            dp[i][j][0] = map[i][j] + max(max(dp[i-1][j][0], dp[i-1][j][1]), dp[i][j-1][0]);
        }
        for(int j=m;j>=1;j--){ // 오른쪽에서 왼쪽으로 비교
            dp[i][j][1] = map[i][j] + max(max(dp[i-1][j][0], dp[i-1][j][1]), dp[i][j+1][1]);
        }
    }
    printf("%d\n", max(dp[n][m][0],dp[n][m][1]));
}