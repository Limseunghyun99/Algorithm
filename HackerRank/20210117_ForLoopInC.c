#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a,b;
    cin >>a>>b;
    
    string num [2] = {"even", "odd"};
    string tmp[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (int i=a;i<=b;i++){
        if(i<=9){
            cout<<tmp[i]<<endl;
        }
        else{
            cout<<num[i%2]<<endl;
        }
    
    }
    return 0;
}
