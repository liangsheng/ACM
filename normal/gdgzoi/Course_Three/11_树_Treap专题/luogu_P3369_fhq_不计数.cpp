// http://gdgzoi.com/showsource.php?id=988005
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
    int ch[N][2], val[N], sz[N];
    unsigned int key[N];

    void init() { e = 0, rt = 0, sz[0] = 0; }

    int add(int x) {
        val[++e] = x, sz[e] = 1;
        ch[e][0] = 0, ch[e][1] = 0;
        key[e] = (unsigned) (engine());
        return e;
    }

    void pushup(int k) {
        sz[k] = sz[ch[k][0]] + sz[ch[k][1]] + 1;
    }

    // 按权值 val 分裂
    void split(int k, int x, int& l, int& r) {
        if (!k) { l = 0, r = 0; return ;}
        if (val[k] <= x) {
            l = k; split(ch[l][1], x, ch[l][1], r);
            pushup(l);
        } else {
            r = k; split(ch[r][0], x, l, ch[r][0]);
            pushup(r);
        }
    }

    int merge(int x, int y) {
        if (!x || !y) return x + y;
        if (key[x] > key[y]) {
            ch[x][1] = merge(ch[x][1], y);
            pushup(x); return x;
        } else {
            ch[y][0] = merge(x, ch[y][0]);
            pushup(y); return y;
        }
    }

    // 在以 k 为根的子树中查找排名第 k 的节点
    int kth(int k, int x) {
        int cnt = sz[ch[k][0]] + 1;
        if (cnt == x) return val[k];
        if (cnt + 1 > x) return kth(ch[k][0], x);
        return kth(ch[k][1], x - cnt);
    }

    // 查找小于 x 的数中最大的数
    int pre(int x) {
        split(rt, x - 1, l, r);
        int ans = kth(l, sz[l]);
        merge(l, r);
        return ans;
    }

    // 查找大于 x 的数中最小的数
    int suf(int x) {
        split(rt, x, l, r);
        int ans = kth(r, 1);
        merge(l, r);
        return ans;
    }

    // 查询 x 的排名, 小于 x 的数的个数 +1
    int rk(int x) {
        split(rt, x - 1, l, r);
        int ans = sz[l] + 1;
        merge(l, r);
        return ans;
    }

    // 插入权值 x
    void insert(int x) {
        split(rt, x, l, r);
        rt = merge(merge(l, add(x)), r);
    }

    // 删除权值 x
    void del(int x) {
        split(rt, x, l, r);
        split(l, x - 1, l, p);
        rt = merge(merge(l, merge(ch[p][0], ch[p][1])), r);
    }

    void print(int k) {
        if (!k) return ;
        print(ch[k][0]);
        cout << val[k] << ' ';
        // printf("(k=%d val=%d sz=%d, l=%d, r=%d)\n", k, val[k], sz[k], ch[k][0], ch[k][1]);
        print(ch[k][1]);
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, op, x;
    cin >> n;
    FhqTreap::init();
    while (n--) {
        cin >> op >> x;
        if (op == 1) {         // 插入 x
            FhqTreap::insert(x);
        } else if (op == 2) {  // 删除 x
            FhqTreap::del(x);
        } else if (op == 3) {  // 查询 x 的排名
            cout << FhqTreap::rk(x) << '\n';
        } else if (op == 4) {  // 查询排名 x 的数
            cout << FhqTreap::kth(FhqTreap::rt, x) << '\n';
        } else if (op == 5) {  // 查询 x 的前驱
            cout << FhqTreap::pre(x) << '\n';
        } else if (op == 6) {  // 查询 x 的后继
            cout << FhqTreap::suf(x) << '\n';
        }
        // FhqTreap::print(FhqTreap::rt);
        // cout << '\n';
    }
    return 0;
}
/**************************************************************
    Problem: 2085
    User: ls01
    Language: C++
    Result: Accepted
    Time:36 ms
    Memory:4132 kb
****************************************************************/