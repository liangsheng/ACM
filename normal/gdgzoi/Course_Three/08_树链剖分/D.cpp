#include <iostream>
#include <vector>
using namespace std;
 
const int MS = 100005;
 
namespace DS {
 
    struct node {
         
        int l, r, rankSum, rankMax, c;
         
#define MIX -1
#define INF 0x3f3f3f3f
#define IGN 0
         
    };
     
    int mergeC(int c1, int c2) {
        if (!c1)
            return c2;
        if (!c2)
            return c1;
        if (c1 == c2)
            return c1;
        return MIX;
    }
     
    node merge(node l, node r) {
        return {l.l, r.r, l.rankSum + r.rankSum, max(l.rankMax, r.rankMax), mergeC(l.c, r.c)};
    }
     
    struct SegmentTree {
         
        node t[MS << 2];
         
#define ls(idx) ((idx) << 1)
#define rs(idx) (ls(idx) | 1)
         
        void build(int l, int r, int idx) {
            t[idx].l = l, t[idx].r = r;
            if (l == r)
                return;
            int m = (l + r) >> 1;
            build(l, m, ls(idx));
            build(m + 1, r, rs(idx));
        }
         
        void overwriteRANK(int pos, int newRank, int idx) {
            if (pos < t[idx].l || t[idx].r < pos)
                return;
            if (t[idx].l == pos && t[idx].r == pos) {
                t[idx].rankMax = t[idx].rankSum = newRank;
                return;
            }
            overwriteRANK(pos, newRank, ls(idx));
            overwriteRANK(pos, newRank, rs(idx));
            t[idx] = merge(t[ls(idx)], t[rs(idx)]);
        }
         
        void overwriteCOLOR(int pos, int newC, int idx) {
            if (pos < t[idx].l || t[idx].r < pos)
                return;
            if (t[idx].l == pos && t[idx].r == pos) {
                t[idx].c = newC;
                return;
            }
            overwriteCOLOR(pos, newC, ls(idx));
            overwriteCOLOR(pos, newC, rs(idx));
            t[idx] = merge(t[ls(idx)], t[rs(idx)]);
        }
         
        node query(int l, int r, int c, int idx) const {
            cout << "l= " << l << ", r= " << r << ", c= " << c << ", idx= " << idx << ' ' << t[idx].l << ' ' <<t[idx].r << '\n';
            if (idx >= (MS << 2)) {
                cout << "FFFFFFFFFFF" << '\n';
                return {0, 0, 0, -INF, IGN};
            }
            if (r < t[idx].l || t[idx].r < l)
                return {0, 0, 0, -INF, IGN};
            if (l <= t[idx].l && t[idx].r <= r) {
                if (t[idx].c == c) return t[idx];
                if (l == r) return {0, 0, 0, -INF, IGN};
            }
            return merge(query(l, r, c, ls(idx)), query(l, r, c, rs(idx)));
        }
     
#undef ls
#undef rs
#undef MIX
     
} tree;
 
}
 
vector<int> g[MS];
int r[MS], c[MS], n, q;
 
namespace HPD {
     
    int fa[MS], siz[MS], dep[MS], son[MS], nt[MS], tn[MS], top[MS], tick;
     
    void dfs1(int u) {
        siz[u] = 1;
        for (int v : g[u]) {
            if (v == fa[u])
                continue;
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]])
                son[u] = v;
        }
    }
     
    void overwriteRANK(int u, int newRank) {
        DS :: tree.overwriteRANK(nt[u], newRank, 1);
    }
     
    void overwriteCOLOR(int u, int newC) {
        DS :: tree.overwriteCOLOR(nt[u], newC, 1);
    }
     
    void dfs2(int u) {
        if (!u)
            return;
        tn[++ tick] = u;
        nt[u] = tick;
        overwriteRANK(u, r[u]);
        overwriteCOLOR(u, c[u]);
        top[u] = (u == son[fa[u]] ? top[fa[u]] : u);
        dfs2(son[u]);
        for (int v : g[u]) {
            if (v == fa[u])
                continue;
            if (v == son[u])
                continue;
            dfs2(v);
        }
    }
     
    void init() {
        DS :: tree.build(1, n, 1);
        dfs1(1);
        dfs2(1);
    }
     
    DS :: node query(int u, int v, int color) {
        cout << "uuuu= " << u << ", v= " << v << ", color= " << color << '\n';
        DS :: node res = {0, 0, 0, -INF, IGN};
        DS :: tree.query(68340, 68346, 3, 1);
        // int cnt = 0;
        // while (top[u] != top[v]) {
        //     if (dep[u] < dep[v])
        //         swap(u, v);
        //     cout << "cnt= " << ++cnt << ", u= " << u << " " << nt[top[u]] << " " << nt[u] << " " << color << '\n';
        //     if (cnt <= 1) {
        //         DS :: node tmp = DS :: tree.query(nt[top[u]], nt[u], color, 1);
        //         // res = DS :: merge(res, tmp);
        //     }
        //     u = fa[top[u]];
        // }
        // if (dep[u] < dep[v])
        //     swap(u, v);
        // res = DS :: merge(res, DS :: tree.query(nt[v], nt[u], color, 1));
        return res;
    }
     
}
 
string command;
int u, v;
 
void input() {
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> r[i] >> c[i];
    for (int i = 1; i < n; i ++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
 
int main() {
    input();
    HPD :: init();
    while (q --) {
        cin >> command >> u >> v;
        cout << command << ' ' << u << ' ' << v << '\n';
        if (command == "CC") {
            HPD :: overwriteCOLOR(u, v);
            c[u] = v;
        }
        if (command == "CW")
            HPD :: overwriteRANK(u, v);
        if (command == "QS")
            cout << HPD :: query(u, v, c[u]).rankSum << '\n';
        if (command == "QM")
            cout << HPD :: query(u, v, c[u]).rankMax << '\n';
    }
    return 0;
}
