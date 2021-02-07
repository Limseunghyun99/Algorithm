#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int num;
    int a,b;
    scanf("%d",&num);
    
    for (int i=1;i<=num;i++){
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n",i, a, b, a+b);
    }
    return 0; 
}
