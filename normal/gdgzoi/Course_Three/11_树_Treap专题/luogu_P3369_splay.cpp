// http://gdgzoi.com/showsource.php?id=988900
#include <bits/stdc++.h>
using namespace std;

namespace Splay {
    const int N = 100005;

    int e, root;
    int ch[N][2], val[N], cnt[N], sz[N], fa[N];

    // 记住这里是 +cnt[k], 不是 +1
    void pushup(int k) { sz[k] = sz[ch[k][0]] + sz[ch[k][1]] + cnt[k]; }

    // 0: x 是 fa[x] 的左儿子; 1: x 是 fa[x] 的右儿子
    int get(int x) { return ch[fa[x]][1] == x; }

    void rotate(int x) {
        int y = fa[x], z = fa[y], k = get(x), w = ch[x][k ^ 1];
        ch[y][k] = w; fa[w] = y;
        ch[z][get(y)] = x; fa[x] = z;
        ch[x][k ^ 1] = y; fa[y] = x;
        pushup(y); pushup(x);  // 这里一定要先 pushup(y); 因为 y 变成了 x 的儿子
    }

    // 将 x 旋转到 goal 的儿子节点; 若 goal == 0, 表示将 x 旋转到 root
    void splay(int x, int goal = 0) {
        while (fa[x] != goal) {
            int y = fa[x], z = fa[y];
            // x, y 同为左儿子或右儿子时, 先旋转 y
            if (z != goal) rotate(get(x) == get(y) ? y : x);
            rotate(x);
        }
        if (!goal) root = x;
    }

    // 将值 x 插入
    void insert(int x) {
        int cur = root, p = 0;
        while (cur && val[cur] != x) p = cur, cur = ch[cur][x > val[cur]];
        if (cur) ++cnt[cur];
        else {
            cur = ++e;
            if (p) ch[p][x > val[p]] = cur;
            ch[cur][0] = ch[cur][1] = 0, fa[cur] = p, val[cur] = x, cnt[cur] = sz[cur] = 1;
        }
        splay(cur);
    }

    // 查找排名第 k 的节点, 假设 k 是合法的, 并且树不为空
    int kth(int k) {
        int cur = root;
        while (true) {
            if (ch[cur][0] && k <= sz[ch[cur][0]]) cur = ch[cur][0];
            else if (k > sz[ch[cur][0]] + cnt[cur]) k -= sz[ch[cur][0]] + cnt[cur], cur = ch[cur][1];
            else { splay(cur); return cur; }
        }
    }

    // 将最靠近 x 的节点旋转到 root, 如果存在 x, 则 val[root] = x; 否则 x 的前驱或者后继为 root
    void find(int x) {
        if (!root) return ;
        int cur = root; while (val[cur] != x && ch[cur][x > val[cur]]) cur = ch[cur][x > val[cur]];
        splay(cur);
    }

    // 返回数 x 的排名(小于 x 的数的个数 +1), 树中不一定存在 x
    int rk(int x) { 
        find(x);
        // 当 val[rooot] >= x 时, 返回 sz[ch[root][0]] + 1;
        // 当 val[rooot] <  x 时, 返回 sz[ch[root][0]] + 1 + 1;
        return sz[ch[root][0]] + (val[root] < x) + 1; 
    }

    // 寻找树中小于 x 的数中最大的数的节点, 树中不一定存在 x
    // init() 的时候会插入最小, 最大 2 个节点, 所以一定存在小于 x 的数
    int pre(int x) {
        find(x); if (val[root] < x) return root;
        int cur = ch[root][0]; while (ch[cur][1]) cur = ch[cur][1];
        splay(cur); return cur;
    }

    // 寻找树中大于 x 的数中最小的数的节点, 树中不一定存在 x
    // init() 的时候会插入最小, 最大 2 个节点, 所以一定存在大于 x 的数
    int suc(int x) {
        find(x); if (val[root] > x) return root;
        int cur = ch[root][1]; while (ch[cur][0]) cur = ch[cur][0];
        splay(cur); return cur;
    }

    // 删除 val 为 x 的节点, 假设一定存在值为 x 的节点
    // 将前驱旋转到 root, 将后继旋转到前驱的儿子
    void remove(int x) {
        // init() 的时候会插入最小, 最大 2 个节点, 所以 x 的前驱和后继一定存在
        int lst = pre(x), nxt = suc(x);
        splay(lst); splay(nxt, lst); 
        int to_del = ch[nxt][0];
        if (cnt[to_del] > 1) { --cnt[to_del]; splay(to_del); }
        else { ch[nxt][0] = 0; splay(nxt); }
    }

    // 打印以 rt 为根的子树
    void flatten(int rt) {
        if (!rt) return;
        flatten(ch[rt][0]);
        printf("(val=%d cnt=%d sz=%d)\n", val[rt], cnt[rt], sz[rt]);
        flatten(ch[rt][1]);
    }

    // e 是节点个数(从 1 开始编号, 见 insert), root 是根节点(初始是 0)
    // 初始插入最大最小 2 个节点
    void init() { 
        e = 0, root = 0, sz[0] = 0, fa[0] = 0; 
        insert(0x7fffffff); insert(0x80000000);
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, op, x;
    cin >> n;
    Splay::init();
    while (n--) {
        cin >> op >> x;
        if (op == 1) {         // 插入 x
            Splay::insert(x);
        } else if (op == 2) {  // 删除 x
            Splay::remove(x);
        } else if (op == 3) {  // 查询 x 的排名
            // init() 的时候插入了最大最小 2 个节点, 所以这里 -1
            cout << Splay::rk(x) - 1 << '\n';
        } else if (op == 4) {  // 查询排名 x 的数
            // init() 的时候插入了最大最小 2 个节点, 所以这里 +1
            cout << Splay::val[Splay::kth(x + 1)] << '\n';
        } else if (op == 5) {  // 查询 x 的前驱
            cout << Splay::val[Splay::pre(x)] << '\n';
        } else if (op == 6) {  // 查询 x 的后继
            cout << Splay::val[Splay::suc(x)] << '\n';
        }
        // Splay::flatten(Splay::root); puts("");
    }
    return 0;
}
/**************************************************************
    Problem: 2085
    User: ls01
    Language: C++
    Result: Accepted
    Time:44 ms
    Memory:4520 kb
****************************************************************/
