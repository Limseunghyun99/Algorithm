#include <iostream>
#include <vector>

using namespace std;

int n, k;                      // 배열 크기(n)와 찾고자 하는 K번째 저장되는 원소
vector<int> arr, temp;         // 입력 배열과 임시 배열 (병합을 위한 버퍼)
int count = 0, result = -1;    // 저장 횟수 카운트와 결과 값

// 병합 (merge) 과정에서 K번째 저장된 원소 찾기
void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, t = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[t++] = arr[i++];
        else temp[t++] = arr[j++];
    }

    while (i <= mid) temp[t++] = arr[i++];  // 왼쪽 배열에 남은 원소 저장
    while (j <= right) temp[t++] = arr[j++]; // 오른쪽 배열에 남은 원소 저장

    // 병합한 배열을 원래 배열에 복사하면서 K번째 저장된 원소 찾기
    for (int x = 0; x < t; x++) {
        count++;  // 저장되는 횟수 증가
        if (count == k) {
            result = temp[x];  // K번째 원소를 찾으면 저장
            return;
        }
        arr[left + x] = temp[x]; // 원본 배열에 병합된 결과 저장
    }
}

// 병합 정렬 (Merge Sort) 수행
void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);       // 왼쪽 부분 정렬
        mergeSort(mid + 1, right);  // 오른쪽 부분 정렬
        merge(left, mid, right);    // 병합 수행
    }
}

int main() {
    cin >> n >> k;
    arr.resize(n);
    temp.resize(n);  // 병합 과정에서 사용할 임시 배열 크기 설정

    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(0, n - 1);

    cout << result << endl;  // K번째 저장된 원소 출력
    return 0;
}
