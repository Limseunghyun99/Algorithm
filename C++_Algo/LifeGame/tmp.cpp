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
    //�� ���� �� ���� ���ڰ� 0�� ���� �ٿ��� ����� �����ϰ�
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
