#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(void) {
	string text, word;
	getline(cin, text);
	
	stringstream ss(text);
	
	int cnt = 0;
	while(ss>>word){ cnt++;}
	
	cout<<cnt;
	return 0;
}
