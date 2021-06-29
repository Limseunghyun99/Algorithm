#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    ifstream fin("main.cpp", ios::in |ios::binary);

    if(!fin){
        cout<<"No Such Files or Dir"<<endl;
        return 0;
    }

    char buff[256];
    int cnt = 0;

    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    cout.setf(ios::uppercase);
    while(!fin.eof()){
        fin.read(buff, 16);
        int num = fin.gcount();
        for(int i=cnt;i<cnt+16;i++){
            cout<<int(buff[i])<<" ";
        }
        cout<<endl;
        cnt  += num;
    }
    cout<<endl;
    return 0;
}
