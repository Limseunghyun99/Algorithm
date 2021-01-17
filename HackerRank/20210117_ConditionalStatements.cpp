#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string tmp[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if(n>9){
        cout<<"Greater than 9"<<endl;
    }
    else{
        cout<<tmp[n]<<endl;
    }

    return 0;
}
