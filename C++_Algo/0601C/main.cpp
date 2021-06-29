#include <iostream>
#include <thread>
using namespace std;
using namespace std::chrono;
static int sum = 0;
void myThread(int e){
    int i = e-250;
    for(;i<e;i++){
        cout<<"Now Sum is "<<(int)sum<<endl;
        sum += i;
        this_thread::sleep_for(milliseconds(5));
    }
}

int main(){
    thread a(myThread, 250);
    thread b(myThread, 500);
    thread c(myThread, 750);
    thread d(myThread,1000);
    a.join();
    b.join();
    c.join();
    d.join();


    cout<<"+++++++++++++++++++++TOTALSUM+++++++++++++++++++++++"<<endl;
    cout<<sum<<endl;


    return 0;
}
