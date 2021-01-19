#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int a,b,tmp;
    scanf("%d %d", &a, &b);
    if(a<b){
        printf("<");
    }
    else if (a>b){
        printf(">");
    }
    else{
        printf("==");
    }    
    
    return 0;
}
