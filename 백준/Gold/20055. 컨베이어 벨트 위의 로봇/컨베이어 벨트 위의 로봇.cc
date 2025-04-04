#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> belt;
vector<bool> robot;

void rotateBelt() {
    // 벨트 회전
    int last = belt.back();
    belt.pop_back();
    belt.insert(belt.begin(), last);

    // 로봇 회전 (마지막 로봇은 떨어져야 함)
    for (int i = N - 1; i > 0; --i)
        robot[i] = robot[i - 1];
    robot[0] = false;
    robot[N - 1] = false; // 내려가는 위치는 항상 비워야 함
}

void moveRobots() {
    // 로봇을 뒤에서부터 이동시킴 (먼저 올라간 로봇부터)
    for (int i = N - 2; i >= 0; --i) {
        if (robot[i] && !robot[i + 1] && belt[i + 1] > 0) {
            robot[i] = false;
            robot[i + 1] = true;
            belt[i + 1]--;
        }
    }
    robot[N - 1] = false; // 내려가는 위치면 내림
}

void putRobot() {
    if (!robot[0] && belt[0] > 0) {
        robot[0] = true;
        belt[0]--;
    }
}

int countZero() {
    int cnt = 0;
    for (int x : belt)
        if (x == 0) cnt++;
    return cnt;
}

int main() {
    cin >> N >> K;
    belt.resize(2 * N);
    robot.resize(N, false);

    for (int i = 0; i < 2 * N; ++i)
        cin >> belt[i];

    int step = 0;
    while (true) {
        step++;
        rotateBelt();
        moveRobots();
        putRobot();

        if (countZero() >= K) break;
    }

    cout << step << endl;
    return 0;
}
