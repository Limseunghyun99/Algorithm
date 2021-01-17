#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b;
    cin>>a>>b;
    int a_size, b_size=0;
    a_size=a.size();
    b_size=b.size();
    cout<<a_size<<" "<<b_size<<endl;
    cout<<a<<b<<endl;
    char a_arr[a_size], b_arr[b_size];
    
    int max=a_size+b_size;
    for(int i=0; i<a_size;i++) a_arr[i]=a[i];
    for(int i=0; i<b_size;i++) b_arr[i]=b[i];
    char tmp=a_arr[0];
    a_arr[0]=b_arr[0];
    b_arr[0]=tmp;
    
    for(int i=0; i<a_size;i++) cout<<a_arr[i];
    cout<<" ";
    for(int i=0; i<b_size;i++) cout<<b_arr[i];
    return 0;
}
