#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int loop;
    int tmp;
    int standard;
    scanf("%d", &loop);
    scanf("%d", &standard);
    
    for (int i=0; i<loop; i++){
        scanf("%d",&tmp);
        if(tmp<standard){
            printf("%d ", tmp);
        }
        }
}
