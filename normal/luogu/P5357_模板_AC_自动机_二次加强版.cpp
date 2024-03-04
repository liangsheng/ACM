#include <bits/stdc++.h>
using namespace std;

/*---------------------------- AC 自动机 begin -----------------------*/
// N 是字符串的个数, M 是字符串的总长度
const int N = 200005, M = 200005, CH = 26;

int n, e;        // n 是字符串的个数, e 是自动机节点的个数
int chd[M][CH];
int wv[M], f[M], q[M], ind[M], cnt[M];
int rev[N], vis[N];

void init() {
    // 注意: chd[], wv[] 都是从 0 开始编号
    e = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    wv[0] = -1;
}

// 注意: id 从 0 开始编号
void add(string& s, int id) {
    int p = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        int id = s[i] - 'a';
        if (chd[p][id] == -1) {
            memset(chd[e], -1, sizeof(chd[e]));
            wv[e] = -1;
            chd[p][id] = e++;
        }
        p = chd[p][id];
    }
    if (wv[p] == -1) wv[p] = id;
    rev[id] = wv[p];  // rev[id] 表示编号为 id 的字符串和编号为 rev[id] 的字符串位于同一节点
}

void build() {
    int p, l = 0, r = 0;
    f[0] = 0;
    fill(ind, ind + e, 0);            // 记录有多少个节点的 fail 指向它
    for (int i = 0; i < CH; i++) {
        if (chd[0][i] != -1) {
            f[chd[0][i]] = 0, cnt[0]++;
            q[r++] = chd[0][i];
        } else chd[0][i] = 0;
    }
    while (l != r) {
        p = q[l++];
        for (int i = 0; i < CH; i++) {
            int v = chd[p][i];
            if (v != -1) {
                f[v] = chd[f[p]][i], ind[f[v]]++;
                q[r++] = v;
            } else chd[p][i] = chd[f[p]][i];
        }
    }
}

void query(string& s) {
    int p = 0;
    fill(cnt, cnt + e, 0);
    for (int i = 0; i < (int) s.size(); i++) {
        p = chd[p][s[i] - 'a'];
        cnt[p]++;
    }

    int l = 0, r = 0;
    for (int i = 0; i < e; i++) if (ind[i] == 0) q[r++] = i;
    fill(vis, vis + n, 0);  // 字符串的编号 id(见 add 函数), 是从 0 开始编号
    while (l != r) {
        p = q[l++];
        if (wv[p] != -1) vis[wv[p]] = cnt[p];
        cnt[f[p]] += cnt[p];
        if (--ind[f[p]] == 0) q[r++] = f[p];
    }
}

/*---------------------------- AC 自动机 end -------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> n) {
        init();
        for (int i = 0; i < n; i++) {
            cin >> s;
            add(s, i);
        }
        build();
        cin >> s;
        query(s);
        for (int i = 0; i < n; i++) cout << vis[rev[i]] << '\n';
    }
    return 0;
}