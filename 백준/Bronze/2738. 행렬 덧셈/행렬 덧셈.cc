#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define DEBUG false

int main()
{
    int row, col = 0;
    int input = 0;
    cin >> row >> col;
    
    int mat[row][col] = {};
    
    if (DEBUG){
        cout<< "row, col"<<row<<col<<endl;
        
        for (int cnt_r = 0; cnt_r<row;cnt_r++){
            for (int cnt_c = 0; cnt_c<col;cnt_c++){
                cout << mat[cnt_r][cnt_c]<<' ';
            }
        cout<<endl;
    }
    }
    
    for (int cnt_r = 0; cnt_r<row;cnt_r++){
        for (int cnt_c = 0; cnt_c<col;cnt_c++){
            cin >> input;
            mat[cnt_r][cnt_c] += input;
        }
    }
    
    for (int cnt_r = 0; cnt_r<row;cnt_r++){
        for (int cnt_c = 0; cnt_c<col;cnt_c++){
            cin >> input;
            mat[cnt_r][cnt_c] += input;
        }
    }
    
    for (int cnt_r = 0; cnt_r<row;cnt_r++){
        for (int cnt_c = 0; cnt_c<col;cnt_c++){
            cout << mat[cnt_r][cnt_c]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}