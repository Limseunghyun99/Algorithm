#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(void) {
    vector<string> croatian = {"c=","c-","dz=","d-","lj","nj","s=","z="};
	string text;
	int i=0;
	cin >> text;
	
	for (int idx=0; idx<croatian.size();idx++){
	    while(true){
	        i = text.find(croatian[idx]);
	        if (i == string::npos)  {
	            break;
	        }
	        text.replace(i,croatian[idx].length(),"#");
	    }
	}
	cout << text.length()<<endl;
	
	return 0;
}
