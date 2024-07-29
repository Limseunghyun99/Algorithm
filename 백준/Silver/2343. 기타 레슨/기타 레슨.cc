#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
 
    int lesson[100002];
    int low, high;
    high = 0; // 최대값
    low = 1; // 최소값
    int a;
    for (int i = 0; i < n; i++){
        cin >> a;
        lesson[i] = a;
        high += a;
    }
    int mid;
    int total; // 녹화중인 블루레이의 남은 공간
    int result = 0;
 
    while (low <= high){
        mid = (low + high) / 2;
        total = mid; // 초기 블루레이 공간
        bool possible = true;
        int cnt = 1; // 블루레이 개수 1로 시작
        for (int i = 0; i < n; i++){
            if(mid < lesson[i]){ // 블루레이 크기가 애초부터 강의보다 작다면 성립 x
                possible = false;
                break;
            }
            if(total < lesson[i]){ // 남은 공간이 다음 강의를 모두 담지 못하면 다음 블루레이 사용
                total = mid; // 다음 블루레이 사용
                cnt++; // 블루레이 개수 카운트
            }
            total -= lesson[i]; // 공간 차감
        }
        if (cnt > m || !possible){ // 성립하지 않거나 정해진 블루레이 개수 보다 더 많이 사용 했을 경우
            low = mid + 1; // 블루레이 크기를 늘려줌
        }else if (cnt <= m){ 
            high = mid - 1; // 블루레이 크기 작게
            result = mid; // 크기 값 저장
        }
    }
    cout << result << endl; // 결과 출력
 
    return 0;
}