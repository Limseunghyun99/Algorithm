#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,tmp;
    int sum=0, i;
    scanf("%d", &n);
    // Testing input
    // printf("%d", *n);
    for (i=1;i<6; i++){
        tmp = n%10;
        sum += tmp;
        n = n/10;
        
    }

    printf("%d", sum);
    return 0;
}
