#include <iostream>
using namespace std;

int main()
{
    int a,b,c,tot=0;
    cin >> a >> b >> c;
    if (a >= b+c) // a가 제일 커서 삼각형이 안되는 경우
        if (tot < 2*(b+c)-1) tot = 2*(b+c)-1;
    if (b >= a+c)
        if (tot < 2*(a+c)-1) tot = 2*(a+c)-1;
    if (c >= a+b)
        if (tot < 2*(a+b)-1) tot = 2*(a+b)-1;
    cout << (tot?tot:a+b+c);
}