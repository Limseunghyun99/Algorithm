#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;
int N, M;
int parent[MAX];

int findParent(int element) {
    if (parent[element] == element) return element;
    return parent[element] = findParent(parent[element]);
}

void Find(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) cout << "YES\n";
    else cout << "NO\n";
}

void Union(int a, int b) {  
    a = findParent(a);
    b = findParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i <= N; i++) parent[i] = i;

    int flag, a, b;
    
    for (int i = 0; i <M; i++) {
        cin >> flag >> a >> b;
        if (!flag) Union(a, b);
        else Find(a, b);
    }
    return 0;
}