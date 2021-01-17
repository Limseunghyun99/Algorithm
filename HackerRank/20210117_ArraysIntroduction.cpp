#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[n-i];
    }
    for(int j=1; j<=n;j++){
        printf("%d ",arr[j]);
    }
    return 0;
}
