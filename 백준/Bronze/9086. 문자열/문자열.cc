#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
    int cases = 0;
    cin >> cases;
    string text;
    char f,l;
    
    for (int i=0; i<cases;i++){
        cin >> text;
        f = text[0];
        l = text[text.length()-1];
        cout<<f<<l<<endl;
    }
    
    return 0;
}