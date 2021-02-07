#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int num;
    scanf("%d",&num);

    for (int i=1;i<10;i++){
        printf("%d * %d = %d\n", num, i, num*i);
    }
    return 0; 
}
