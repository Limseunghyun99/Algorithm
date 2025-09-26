#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(void) {
	string word;
	int flag = 1;
	cin >> word;
	int len = word.length();
// 	cout<<"len"<<len<<endl;;
	
	for (int idx=0;idx<len/2;idx++){
	    if (word[idx] != word[len-idx-1]){
	       // cout <<"idx"<< word[idx] << "-idx"<<word[len-idx-1]<<endl;
	        flag = 0;
	        break;
	    }
	    else    continue;
	}
	cout <<flag;
}
