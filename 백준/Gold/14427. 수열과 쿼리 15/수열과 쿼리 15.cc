#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, int>;

const long long INF = (1LL<<60);

struct SegTree {
    int n;
    vector<pii> tree;
    
    SegTree(int _n): n(_n) {
        tree.assign(4*n, {INF, -1});
    }
    
    // 두 쌍 중 더 작은 값을, 값이 같으면 인덱스 작은 쪽을 반환
    pii merge(const pii &a, const pii &b) {
        if (a.first < b.first) return a;
        if (b.first < a.first) return b;
        // 값이 같으면 인덱스 비교
        return (a.second < b.second ? a : b);
    }
    
    void build(int node, int l, int r, const vector<long long> &A) {
        if (l == r) {
            tree[node] = {A[l], l};
        } else {
            int mid = (l + r) >> 1;
            build(node*2, l, mid, A);
            build(node*2+1, mid+1, r, A);
            tree[node] = merge(tree[node*2], tree[node*2+1]);
        }
    }
    
    // idx 위치를 val로 업데이트
    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            tree[node] = {val, l};
        } else {
            int mid = (l + r) >> 1;
            if (idx <= mid) update(node*2, l, mid, idx, val);
            else           update(node*2+1, mid+1, r, idx, val);
            tree[node] = merge(tree[node*2], tree[node*2+1]);
        }
    }
    
    // 전체 구간의 최솟값 인덱스 조회
    pii query() {
        return tree[1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N+1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    
    SegTree seg(N);
    seg.build(1, 1, N, A);

    int M;
    cin >> M;
    while (M--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            long long v;
            cin >> i >> v;
            seg.update(1, 1, N, i, v);
        } else if (t == 2) {
            pii res = seg.query();
            cout << res.second << "\n";
        }
    }
    return 0;
}
