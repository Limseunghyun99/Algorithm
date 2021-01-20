#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int score;
    scanf("%d", &score);
    
    if(score>=90){
        printf("A");
        return 0;
    }
    else if(score>=80){
        printf("B");
        return 0;
    }
    else if(score>=70){
        printf("C");
        return 0;
    }
    else if(score>=60){
        printf("D");
        return 0;
    }
    else{
        printf("F");
    }
    return 0;
    
    
    
    
}
