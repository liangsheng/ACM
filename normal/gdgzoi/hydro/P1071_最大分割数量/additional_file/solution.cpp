#include <bits/stdc++.h>
using namespace std;

int solve(string s, int k) {
    int n = s.size();

    if (k == 26) return 1;
    if (k == 1) {
        int maxi = 1, cnt = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (i + 1 < n && s[i + 1] == s[i]) i++;
            maxi = max(maxi, i - j + 1);
            cnt++;
        }
        return cnt + min(2, maxi - 1);
    }

    auto gao = [&](int k, vector<int>& h) {
        vector<int> c(26, 0), R(n + 1, n);
        int p = 0, cnt = 0, st = 0, id;
        for (int i = 0; i < n; i++) {
            while (p < n && cnt <= k) {
                id = s[p] - 'a';
                if (c[id] == 0) cnt++, st ^= (1 << id);
                c[id]++;
                p++;
            }
            if (cnt > k) R[i] = p - 2, h[i] = (st ^ (1 << id));
            else R[i] = n - 1, h[i] = st;
            if (--c[s[i] - 'a'] == 0) cnt--, st ^= (1 << (s[i] - 'a'));
        }
        return R;
    };

    vector<int> h(n + 1, 0), h2(n + 1, 0);
    vector<int> R = gao(k, h), R2 = gao(k - 1, h2);

    vector<int> f(n + 2, 0);
    for (int i = n - 1; i >= 0; i--) f[i] = 1 + f[R[i] + 1];
    
    int ans = f[0], st = (1 << 26) - 1;
    for (int i = 0, t = 0; i < n; i = R[i] + 1, t++) {
        vector<int> c(26, 0);
        for (int p = i; p <= R[i]; p++) {
            if (c[s[p] - 'a'] > 0) {
                int res;
                if (p <= R2[i]) res = t + 1 + f[R2[i] + 1];
                else {
                    // 可能找不到和 h[i] 和 h2[p + 1] 都不相同的
                    if ((h[i] | h2[p + 1]) == st) res = t + 1 + 1 + f[R[p + 1] + 1];
                    else res = t + 1 + 1 + f[R2[p + 1] + 1];
                }
                ans = max(ans, res);
            }
            c[s[p] - 'a']++;
        }
    }
    return ans;
}

int main() {
    // 下面 2 句是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int k;
    while (cin >> s >> k) cout << solve(s, k) << '\n';
    return 0;
}