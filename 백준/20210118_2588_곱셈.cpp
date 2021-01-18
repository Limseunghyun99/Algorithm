#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int inp1, inp2;
    int out1, out2, out3, res;
    scanf("%d %d", &inp1, &inp2);
    out1 = inp1 * ((inp2%100)%10);
    out2 = inp1 * ((inp2%100)/10);
    out3 = inp1 * (inp2/100);
    res = inp1 * inp2;
    printf("%d\n%d\n%d\n%d", out1, out2, out3, res);
}
