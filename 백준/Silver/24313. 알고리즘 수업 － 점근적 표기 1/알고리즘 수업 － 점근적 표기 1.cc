#include <iostream>
#define DEBUG false
using namespace std;

int main() {
    /*  f(x) = ax + b
    *   input = a, b > C > n0
    *   if ( a*n0 + b > C*n0 ) : 0
    *   else : 1
    */

   int a, b, C, n = 0;

   cin >> a >> b;
   cin >> C;
   cin >> n;

   int f = a*n + b;
   int g = C*n;
   
   if (DEBUG){
       cout<<"F:"<<f<<endl;
       cout<<"G:"<<g<<endl;
   }

   if (f<=g && a <= C){
    cout<<"1"<<endl;
   }
   else{
    cout << "0" <<endl;
   }

    return 0;
}
