#include <iostream>

using namespace std;

int get_min(int x, int y)
{
    if (x<y){
        return x;
    }
    else{
        return y;
    }
}

int main() {
    int coin[101];
    int result[100001]={0,};
	int n, k;
	cin >> n >> k;
    
    for(int i=1; i<=k;++i){
        result[i]=100001;
    }
    
    for(int i=1; i<= n; ++i)
    {
        cin>>coin[i];
        
        for(int j=coin[i];j<=k;j++){
            result[j]=get_min(result[j],result[j-coin[i]]+1);
        }
    }
    if(result[k]==100001){
        cout<<"-1"<<endl;
    }
    else{
        cout<<result[k]<<endl;
    }
    return 0;   
}
