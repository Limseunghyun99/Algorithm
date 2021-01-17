#include <stdio.h>
#include <math.h>

void update(int *a,int *b) {
    int num1 = *a;
    int num2 = *b;
    int tmp = 0;

    int sum =0;
    int diff =0;
    sum = num1 + num2;
    tmp = num1 - num2;
    diff = abs(tmp);

    *a = sum;
    *b = diff;

}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

