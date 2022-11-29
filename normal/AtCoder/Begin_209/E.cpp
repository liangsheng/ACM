#include <bits/stdc++.h>
using namespace std;

const int N = 200005, P = 52, M = 52 * 52 * 52;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    auto str_to_int = [](string s) {
        int ans = 0;
        for (auto& c: s) {
            if (c >= 'a' && c <= 'z') ans = ans * 52 + c - 'a';
            else ans = ans * 52 + c - 'A' + 26;
        }
        return ans;
    };
    int n, win = 1, loss = 0;
    string s;
    while (cin >> n) {
        vector<vector<int> > g(M);
        vector<int> cnt(M, 0);
        vector<int> f(M, -1);
        vector<int> sc(n);
        for (int i = 0; i < n; i++) {
            cin >> s;
            int x = str_to_int(s.substr(0, 3));
            int y = str_to_int(s.substr(s.size() - 3, 3));
            g[y].push_back(x);
            cnt[x]++;
            sc[i] = y;
        }
        queue<int> q;
        for (int i = 0; i < M; i++) if (cnt[i] == 0) {
            f[i] = win;
            q.push(i);
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (f[x] == win) for (int y: g[x]) {
                if (f[y] == -1) {
                    f[y] = loss;
                    q.push(y);
                }
            }
            if (f[x] == loss) for (int y: g[x]) {
                if (--cnt[y] == 0) {
                    f[y] = win;
                    q.push(y);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (f[sc[i]] == win) puts("Takahashi ");
            else if (f[sc[i]] == loss) puts("Aoki");
            else puts("Draw");
        }
    }
    return 0;
}