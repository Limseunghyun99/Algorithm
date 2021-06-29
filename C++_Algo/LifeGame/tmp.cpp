#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    //N
    int cellSize = 0;
    cin>>cellSize;
    int cycle = 0;
    cin>>cycle;
    //양 끝의 셀 옆에 숫자가 0인 셀을 붙여서 계산을 용이하게
    int cell [cellSize+2];
    cell[0] = 0;
    cell[cellSize+2] = 0;

    //set cell value
    for(int i =1; i<cellSize; I++) cin>>cell[i];

    for (int k = 0; k<cycle; k++){
    // in case sum of neighbor's num is < 3 or > 7 -> decrease num
	if ((cell[i-1] + cell[i+1]) < 3 || (cell[i-1] + cell[i+1]) > 7) cell[i]--;
	else if(cell[i-1] + cell[i+1] <7 && cell[i-1] + cell[i+1] > 3 && cell[i] <9) cell[i]++;
    }
}
