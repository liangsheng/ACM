#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// https://leetcode.cn/contest/weekly-contest-399/ranking/
// 第一名 fmota 的 D 题
// 可以通过 https://loj.ac/p/130 
template<typename T>
struct segtree {
    vector<T> t;
    int n;
    segtree(int n): n(n) {
        t.assign(2 * n, T());
    }
    void update(int p, T v){
        for(t[p += n] = v; p >>= 1; )
            t[p] = t[p<<1] + t[p<<1|1];
    }
    void add(int p, T v){
        p += n;
        t[p] = t[p] + v;
        while(p >>= 1) t[p] = t[p<<1] + t[p<<1|1];
    }
    T query(int l, int r){
        T cl = T(), cr = T();
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l&1) cl = cl + t[l++];
            if(r&1) cr = t[--r] + cr;
        }
        return cl + cr;
    }
};

int main() {
    // 这两句是为了让 cin 更快
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, x, y, z;
	cin >> n >> m;
    segtree<LL> seg(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        seg.update(i, x);
    }

    while (m--) {
        cin >> x >> y >> z;
        if (x == 1) seg.add(y - 1, z);
        else cout << seg.query(y - 1, z) << '\n';
    }

    return 0;
}