#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
int dx[] = {-1, 0, 1, 0}; // 상우하좌
int dy[] = {0, 1, 0, -1};

vector<vector<int>> classroom;
map<int, vector<int>> likes;

bool inRange(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

int countAdjLikes(int x, int y, int student) {
    int count = 0;
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (inRange(nx, ny) && find(likes[student].begin(), likes[student].end(), classroom[nx][ny]) != likes[student].end()) {
            count++;
        }
    }
    return count;
}

int countAdjEmpty(int x, int y) {
    int count = 0;
    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (inRange(nx, ny) && classroom[nx][ny] == 0) {
            count++;
        }
    }
    return count;
}

void seatStudent(int student) {
    int maxLike = -1, maxEmpty = -1;
    int bestX = -1, bestY = -1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (classroom[i][j] != 0) continue;
            int like = countAdjLikes(i, j, student);
            int empty = countAdjEmpty(i, j);

            if (like > maxLike || (like == maxLike && empty > maxEmpty) ||
                (like == maxLike && empty == maxEmpty && (i < bestX || (i == bestX && j < bestY)))) {
                maxLike = like;
                maxEmpty = empty;
                bestX = i;
                bestY = j;
            }
        }
    }

    classroom[bestX][bestY] = student;
}

int getSatisfaction() {
    int score = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int student = classroom[i][j];
            int likeCount = countAdjLikes(i, j, student);
            if (likeCount == 1) score += 1;
            else if (likeCount == 2) score += 10;
            else if (likeCount == 3) score += 100;
            else if (likeCount == 4) score += 1000;
        }
    }
    return score;
}

int main() {
    cin >> N;
    classroom.assign(N, vector<int>(N, 0));
    vector<int> order;

    for (int i = 0; i < N * N; ++i) {
        int student, a, b, c, d;
        cin >> student >> a >> b >> c >> d;
        likes[student] = {a, b, c, d};
        order.push_back(student);
    }

    for (int student : order) {
        seatStudent(student);
    }

    cout << getSatisfaction() << endl;
    return 0;
}
