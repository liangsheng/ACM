#include <bits/stdc++.h>
#define sc1(x) cout << #x << "= " << x << '\n'
#define sc2(x, y) cout << #x << "= " << x << ", " << #y << "= " << y << '\n'
#define sc3(x, y, z) cout << #x << "= " << x << ", " << #y << "= " << y << ", " << #z << "= " << z << '\n'
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

namespace FhqTreap {
    const int N = 100005;
    mt19937 engine(114514);

    int e, rt, l, p, r;
    int ch[N][2], val[N], sz[N], tag[N];
    unsigned int key[N];

    int add(int x) {
        val[++e] = x, sz[e] = 1, tag[e] = 0;
        ch[e][0] = 0, ch[e][1] = 0;
        key[e] = (unsigned) (engine());
        return e;
    }

    void pushup(int k) {
        sz[k] = sz[ch[k][0]] + sz[ch[k][1]] + 1;
    }

    void pushdown(int k) {
        if (!k || !tag[k]) return ;
        swap(ch[k][0], ch[k][1]);
        if (ch[k][0]) tag[ch[k][0]] ^= 1;
        if (ch[k][1]) tag[ch[k][1]] ^= 1;
        tag[k] = 0;
    }

    // 按节点数 sz 分裂
    void split(int k, int x, int& l, int& r) {
        if (!k) { l = 0, r = 0; return ;}
        pushdown(k);
        // 注意: 这里要 sz[ch[k][0]] + 1, 按权值分裂时是: val[k]
        if (sz[ch[k][0]] + 1 <= x) {
            // 这里是 x - sz[ch[k][0]] - 1, 按权值分裂时是 x
            l = k; split(ch[l][1], x - sz[ch[k][0]] - 1, ch[l][1], r);
            pushup(l);
        } else {
            r = k; split(ch[r][0], x, l, ch[r][0]);
            pushup(r);
        }
    }

    int merge(int x, int y) {
        if (!x || !y) return x + y;
        pushdown(x); pushdown(y);
        if (key[x] > key[y]) {
            ch[x][1] = merge(ch[x][1], y);
            pushup(x); return x;
        } else {
            ch[y][0] = merge(x, ch[y][0]);
            pushup(y); return y;
        }
    }

    void print(int k) {
        if (!k) return ;
        pushdown(k);
        print(ch[k][0]);
        cout << val[k] << ' ';
        // printf("(k=%d val=%d sz=%d, l=%d, r=%d)\n", k, val[k], sz[k], ch[k][0], ch[k][1]);
        print(ch[k][1]);
    }

    // 将 [u, v] 翻转
    void reverse(int u, int v) {
        // l: [1, u - 1], p: [u, v], r: [v + 1, n]
        split(rt, u - 1, l, r);
        split(r, v - u + 1, p, r);
        tag[p] ^= 1;
        rt = merge(l, merge(p, r));  // 记住最后要将返回值赋值给 rt
    }

    // 初始化链
    void init(vector<int>& A) { 
        e = 0, rt = 0, sz[0] = 0; 
        for (int x : A) rt = merge(rt, add(x));
    }

    // o(n) 单调栈初始化
    // 见 https://oiwiki.org/ds/treap
    void init_quick(vector<int>& A) {
        e = 0, rt = 0, sz[0] = 0;

        int h = 0, n = A.size();
        vector<int> st(n);
        for (int x : A) {
            int id = add(x);
            while (h > 0 && key[st[h - 1]] < key[id]) h--;
            if (h == 0) ch[id][0] = rt, rt = id;
            else ch[id][0] = ch[st[h - 1]][1], ch[st[h - 1]][1] = id;
            st[h++] = id;
        }
        // 建完树后更新 sz
        h = 0;
        st[h++] = rt;
        for (int i = 0; i < n; i++) {
            if (ch[st[i]][0]) st[h++] = ch[st[i]][0];
            if (ch[st[i]][1]) st[h++] = ch[st[i]][1];
        }
        for (int i = n - 1; i >= 0; i--) sz[st[i]] = sz[ch[st[i]][0]] + sz[ch[st[i]][1]] + 1;
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, m, l, r;
    cin >> n >> m;
    vector<int> A(n); for (int i = 0; i < n; i++) A[i] = i + 1;
    FhqTreap::init(A);
    // FhqTreap::init_quick(A);
    while (m--) {
        cin >> l >> r;
        FhqTreap::reverse(l, r);
    }
    FhqTreap::print(FhqTreap::rt);
    cout << '\n';
    return 0;
}