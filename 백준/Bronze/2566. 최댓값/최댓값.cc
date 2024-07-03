#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define DEBUG false

int main()
{
    int row = 9;
    int col = 9;
    int input = 0;
    int ans = 0;
    int ans_r = 0;
    int ans_c = 0;
    // cin >> row >> col;
    
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
            mat[cnt_r][cnt_c] = input;
        }
    }
    
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
            if (mat[cnt_r][cnt_c] > ans){
                ans = mat[cnt_r][cnt_c];
                ans_r = cnt_r;
                ans_c = cnt_c;
            }
        }
    }
    cout << ans << endl;
    cout << ans_r+1 << " " << ans_c+1;
}