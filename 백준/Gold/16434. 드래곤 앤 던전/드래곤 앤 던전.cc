#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Room {
    int type;
    ll a, h;
};

int N;
ll initialAtk;
vector<Room> rooms;

// 해당 체력으로 클리어 가능한지 확인
bool canClear(ll maxHp) {
    ll curHp = maxHp;
    ll atk = initialAtk;

    for (int i = 0; i < N; ++i) {
        if (rooms[i].type == 1) {
            // 몬스터 방
            ll monsterAtk = rooms[i].a;
            ll monsterHp = rooms[i].h;

            // 몇 번 때려야 몬스터를 잡나?
            ll turnsToKill = (monsterHp + atk - 1) / atk;
            ll turnsToDie = (curHp + monsterAtk - 1) / monsterAtk;

            // 용사는 선공, 몬스터가 (turnsToKill - 1)번 때릴 수 있음
            curHp -= monsterAtk * (turnsToKill - 1);

            if (curHp <= 0) return false;
        } else {
            // 포션 방
            atk += rooms[i].a;
            curHp = min(curHp + rooms[i].h, maxHp); // 최대 체력 이상 회복 불가
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> initialAtk;
    rooms.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> rooms[i].type >> rooms[i].a >> rooms[i].h;
    }

    ll low = 1, high = 1e18;
    ll answer = high;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (canClear(mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
