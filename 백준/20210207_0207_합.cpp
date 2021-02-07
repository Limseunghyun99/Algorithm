#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int num, sum=0;
    scanf("%d",&num);

    for (int i=0;i<=num;i++){
        sum=sum+i;
    }
    printf("%d",sum);
    return 0; 
}
