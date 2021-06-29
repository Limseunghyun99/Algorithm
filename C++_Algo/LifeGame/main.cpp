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
    //[
    int cell [cellSize+2][cycle];
    for(int tmp = 0; tmp<cycle+2;tmp++)
    {
        cell[0][tmp] = 0;
        cell[cellSize+2][tmp] = 0;
    }

    //set cell value
    for(int i =1; i<cellSize+1; i++) cin>>cell[i][0];

    //Loop for Cycle times
    for (int k=0; k<cycle; k++){


    //update whole Cells
    for (int i = 1; i<cellSize+1; i++){

        //Edited By Bear for Debugging
       cout<<"K value : " << k<<"I value : "<<i<< "cell value : "<<cell[0][k]<<endl;


    // in case sum of neighbor's num is < 3 or > 7 -> decrease num
	if ((cell[i-1][k] + cell[i+1][k]) < 3 || (cell[i-1][k] + cell[i+1][k]) > 7) cell[i][k+1]= cell[i][k] -1;
	else if(cell[i-1][k] + cell[i+1][k] <7 && cell[i-1][k] + cell[i+1][k] > 3 && cell[i][k] <9) cell[i][k+1] = cell[i][k] +1 ;
    }
    }
    //print cell
    for(int i=1;i<cellSize;i++) cout<<cell[i][cycle]<<" ";

}
