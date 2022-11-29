#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int T, n, m;
int a[N], f[N];
vector<pair<int, int> > ans;
map<int, vector<int> > h;
map<int, int> id;

bool gao(int x, int y) {
    ans.clear();
    memset(f, 0, sizeof(f));
    f[x] = 1, f[y] = 1;
    id.clear();
    for (auto it: h) id[it.first] = 0;

    int d, p = y - 1, q;
    ans.push_back(make_pair(x, y));
    while (ans.size() != n) {
        d = a[ans.rbegin()->second];
        while (f[p]) p--;
        f[p] = 1;
        q = d - a[p];
        // printf("d= %d %d %d\n", d, p, q);
        if (!id.count(q) || id[q] == h[q].size()) break;
        while (id[q] < h[q].size() && f[h[q][id[q]]]) id[q]++;
        if (id[q] == h[q].size()) break;
        // printf("d= %d %d %d %d %d %d\n", d, p, q, id[q], h[q][id[q]], f[h[q][id[q]]]);
        ans.push_back(make_pair(h[q][id[q]], p));
        f[h[q][id[q]]] = 1;
    }
    return ans.size() == n;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        m = 2 * n;
        for (int i = 0; i < m; i++) cin >> a[i];
        if (n == 1) {
            puts("YES");
            cout << a[0] + a[1] << '\n';
            cout << a[0] << ' ' << a[1] << '\n';
            continue;
        }
        sort(a, a + m);
        h.clear();
        for (int i = 0; i < m; i++) h[a[i]].push_back(i);

        bool yes = 0;
        for (int i = m - 2; i >= 0; i--) {
            if (gao(i, m - 1)) {
                puts("YES");
                cout << a[ans.begin()->first] + a[ans.begin()->second] << '\n';
                for (pair<int, int> it: ans) cout << a[it.first] << ' ' << a[it.second] << '\n';
                yes = 1;
                break;
            }
        }
        if (!yes) puts("NO");
    }
    return 0;
}