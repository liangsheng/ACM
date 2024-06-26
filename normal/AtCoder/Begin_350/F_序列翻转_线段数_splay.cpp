#include <bits/stdc++.h>
using namespace std;

namespace Splay {
    const int N = 500005;

    int e, root;
    int ch[N][2], val[N], cnt[N], sz[N], fa[N], tag[N], re[N];

    // 记住这里是 +cnt[k], 不是 +1
    void pushup(int k) { sz[k] = sz[ch[k][0]] + sz[ch[k][1]] + cnt[k]; }

    void change_val(int k) {
        if (val[k] >= 'a') val[k] -= 'a' - 'A';
        else val[k] += 'a' - 'A';
    }

    void pushdown(int k) {
        if (!k) return ;
        if (tag[k]) {
            swap(ch[k][0], ch[k][1]);
            if (ch[k][0]) tag[ch[k][0]] ^= 1;
            if (ch[k][1]) tag[ch[k][1]] ^= 1;
            tag[k] = 0;
        }
        if (re[k]) {
            change_val(k);
            if (ch[k][0]) re[ch[k][0]] ^= 1;
            if (ch[k][1]) re[ch[k][1]] ^= 1;
            re[k] = 0;
        }
    }

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

    // 查找排名第 k 的节点, 假设 k 是合法的, 并且树不为空
    int kth(int k) {
        int cur = root;
        while (true) {
            pushdown(cur);  // 注意下放标记
            if (ch[cur][0] && k <= sz[ch[cur][0]]) cur = ch[cur][0];
            else if (k > sz[ch[cur][0]] + cnt[cur]) k -= sz[ch[cur][0]] + cnt[cur], cur = ch[cur][1];
            else { splay(cur); return cur; }
        }
    }

    // 打印以 rt 为根的子树
    void flatten(int rt, int l, int r) {
        if (!rt) return;
        pushdown(rt);
        flatten(ch[rt][0], l, r);
        if (val[rt] >= l && val[rt] <= r) cout << char(val[rt]);
        // printf("(k=%d val=%d cnt=%d sz=%d)\n", rt, val[rt], cnt[rt], sz[rt]);
        flatten(ch[rt][1], l, r);
    }

    int build(int l, int r, int rt) {
        if (l > r) return 0;
        int p = (l + r) / 2;
        fa[p] = rt, sz[p] = r - l + 1;
        ch[p][0] = build(l, p - 1, p);
        ch[p][1] = build(p + 1, r, p);
        pushup(p);
        return p;
    }

    // e 是节点个数(从 1 开始编号, 见 insert), root 是根节点(初始是 0)
    // 初始插入最小最大 2 个哨兵节点, A[0] = -1, A[n + 1] = n + 1;
    void init(vector<int>& A) { 
        e = 0, sz[0] = 0, fa[0] = 0; 
        int n = A.size();
        for (int x : A) {
            int cur = ++e;
            val[cur] = x, cnt[cur] = sz[cur] = 1, tag[cur] = 0;
        }
        root = build(1, e, 0);
    }

    void reverse(int l, int r) {
        l++, r++;  // 初始插入最小最大 2 个哨兵节点, 所以这里 l++, r++
        // 先通过 kth() 下放 tag
        int a = kth(l - 1), b = kth(r + 1);
        // 将 l - 1 旋转到 root, 将 r + 1 旋转到 l - 1 的右儿子
        splay(a); splay(b, a);
        tag[ch[b][0]] ^= 1;  
        re[ch[b][0]] ^= 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int m = s.size(), n = 0;
    vector<int> c(m), L(m), R(m);
    vector<int> fc(m);
    for (int i = 0; i < m; i++) {
        if (s[i] == '(') c[i] = -2;
        else if (s[i] == ')') c[i] = -1;
        else c[i] = ++n, fc[n] = s[i];
    }
    if (n == 0) {
        cout << "\n";
        return 0;
    }
    int p = m + 1;
    for (int i = m - 1; i >= 0; i--) {
        if (c[i] >= 1) p = c[i];
        else if (c[i] == -2) R[i] = p;
    }
    p = 0;
    for (int i = 0; i < m; i++) {
        if (c[i] >= 1) p = c[i];
        else if (c[i] == -1) L[i] = p;
    }
    // for (int i = 0; i < m; i++) {
    //     if (c[i] == -2) cout << "i= " << i << ", R[i]= " << R[i] << '\n';
    //     if (c[i] == -1) cout << "i= " << i << ", L[i]= " << L[i] << '\n';
    // }

    vector<pair<int, int>> q;
    vector<int> A = {0};
    stack<int> st;
    for (int i = 0; i < m; i++) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') {
            q.push_back({R[st.top()], L[i]});
            st.pop();
        } else A.push_back(s[i]);
    }
    A.push_back(256);
    // for (int i = 1; i <= n; i++) cout << A[i] << ' ';
    // cout << '\n';
    // for (auto [l, r] : q) cout << l << ' ' << r << '\n';

    // int n, m, l, r;
    // cin >> n >> m;
    // vector<int> A; 
    // A.push_back(0);      // 在最前面插入哨兵节点
    // for (int i = 1; i <= n; i++) A.push_back(i);
    // A.push_back(n + 1);  // 在最后面插入哨兵节点
    Splay::init(A);
    // Splay::flatten(Splay::root, 65, 200);
    // cout << '\n';
    for (auto [l, r] : q) {
        Splay::reverse(l, r);
    }
    Splay::flatten(Splay::root, 65, 200);
    cout << '\n';
    return 0;
}
