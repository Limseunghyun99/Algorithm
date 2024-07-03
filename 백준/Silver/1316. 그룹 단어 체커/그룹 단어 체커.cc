#include <iostream>
#include <string>
using namespace std;

#define DEBUG false

int main()
{
    int numOfInput = 0;
    int ans = 0;
    cin>>numOfInput;
    
    string word;
    
    for (int cnt = 0; cnt <numOfInput; cnt++){
        // flag to determine whether word is groupword
        bool groupWord = true;
        string tmp = "";
        cin>>word;
        
        if (DEBUG) {
            cout<<"Current Word"<<word<<endl;
        } 
        
        for (int idx = 0; idx < word.length();idx++){
            if(word[idx]==word[idx+1]){
                continue;
            }
            else{
                int tmp_w = tmp.find(word[idx]);
                if (tmp_w != string::npos){
                    groupWord = false;
                }
                else {
                    tmp.push_back(word[idx]);
                }
            }
        }
        if (groupWord) {
            ans++;
        }
        
    }
    cout<<ans<<endl;
    return 0;
}