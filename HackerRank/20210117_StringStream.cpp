#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

void parseInts(string str) {
    
	string stringbuffer;
    istringstream ss(str);
    while(getline(ss, stringbuffer, ',')){
        cout<<stringbuffer<<endl;
    }   
}

int main() {
    string str;
    cin >> str;
    parseInts(str);
    /*
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    */
    
    return 0;
}
