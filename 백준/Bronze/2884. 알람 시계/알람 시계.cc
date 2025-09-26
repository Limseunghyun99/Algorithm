#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int h,m;
    scanf("%d %d",&h, &m);
    int sum = h*60 + m;
    int tmp = sum - 45;
    if(tmp<0){
        tmp = tmp + 1440;
    }
    h = tmp/60;
    m = tmp%60;
    printf("%d %d",h,m);
    return 0;

    
}