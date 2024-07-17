#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define endl "\n"
#define MAX 10 + 1
using namespace std;

int N, Answer = 20181681;
int Person[MAX];                     // 인구수를 저장하기 위한 배열
bool Connect[MAX][MAX];     // 구역들 간의 연결관계를 저장하기 위한 배열 [x][y] -> x는 y와 연결됨
bool Select[MAX];                   // 조합 구현 시, 뽑은 데이터에 대한 체크를 저장하기 위한 배열
bool is_visited[MAX];              // BFS탐색 시, 방문 탐색을 체크하기 위한 배열

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int x; cin >> x;
        Person[i] = x;
    }
    for (int i = 1; i <= N; i++)
    {
        int Cnt; cin >> Cnt;
        for (int j = 0; j < Cnt; j++)
        {
            int a; cin >> a;
            Connect[i][a] = true;
            Connect[a][i] = true;
        }
    }
}
// 연결 여부 (T/F) 리턴
// 2번 조건 (연결 여부 판단 함수)
bool is_connected(vector<int> V, bool T) {
    memset(is_visited, false, sizeof(is_visited)); // 메모리 할당
    queue<int> Q;
    Q.push(V[0]);
    is_visited[V[0]] = true; // 자기자신은 true
    int cnt = 1; // counter

    while (Q.empty() == 0) // 빌때까지
    {
        int x = Q.front();
        Q.pop(); // 지금 구역구 제거

        /*
        *   @brief BFS 탐색 조건 3개
        *   조건 1) 현재 구역과 탐색 구역이 연결되어 있는가
        *   조건 2) 탐색하려는 구역이 선거구에 속해있는가
        *   조건 3) 아직 방문하지 않은 구역인가
        *
        *   x = 현재 구역, i = 탐색할 구역
        */
        for (int i = 1; i <= N; i++) {
            if (Connect[x][i] == true && Select[i] == T && is_visited[i] == false) {
                is_visited[i] = true;
                cnt++;
                Q.push(i);
            }
        }
    }

    if (V.size() == cnt) return true;
    return false;
}

/*
* @brief 선거구가 유효한지 확인하는 함수
* 조건 1) 선거구에 속한 지역이 1개 이상인가
* 조건 2) 선거구에 포함된 구역들 끼리 모두 연결되어 있는가
*/
bool Check() {
    vector<int> A, B;       // 선거구 A,B
    for (int i = 1; i <= N; i++) {
        if (Select[i] == true) A.push_back(i);
        else B.push_back(i);
    }


    /* 1번 조건 Check */
    if (A.size() == 0 || B.size() == 0) return false;

    /* 2번 조건 Check */
    bool AState = is_connected(A, true);
    if (AState == false) return false;

    bool BState = is_connected(B, false);
    if (BState == false) return false;

    return true;
}

/* @brief A,B 인구수 차이를 계산 */
void Calc() {
    int A_pop, B_pop, Diff;
    A_pop = B_pop = 0;

    for (int i = 1; i <= N; i++) {
        if (Select[i] == true) A_pop = A_pop + Person[i];
        else B_pop = B_pop + Person[i];
    }
    Diff = abs(A_pop - B_pop);
    if (Answer > Diff) Answer = Diff;

}

/*@brief DFS 구현 함수*/
void DFS(int Idx, int Cnt) {
    if (Cnt >= 1) {
        if (Check() == true) Calc();
    }
    for (int i = Idx; i <= N; i++) {
        if (Select[i] == true) continue;
        Select[i] = true;
        DFS(i, Cnt + 1);
        Select[i] = false;
    }
}

void Solution()
{
    DFS(1, 0);

    if (Answer == 20181681) cout << -1 << endl;
    else cout << Answer << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}