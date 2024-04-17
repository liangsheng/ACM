#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h, w;
    cin >> n >> h >> w;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    
    bool ok = false;
    vector<int> c;
    vector<vector<int>> d(h, vector<int>(w, 0));

    function<bool(int)> dfs = [&](int id) {
        // cout << "id= " << id << " " << c.size() << '\n';
        if (id == (int) c.size()) return true;
        for (int k = 0; k < 2; k++) {
            // cout << "k= " << k << '\n';
            int x = a[c[id]], y = b[c[id]], p = -1, q = -1;
            if (k == 1) swap(x, y);
            for (int i = 0; i + x <= h; i++) for (int j = 0; j + y <= w; j++) if (d[i][j] == 0 && p == -1) {
                p = i, q = j;
                break;
            }
            // cout << "p= " << p << ", q= " << q << ' ' << d[0][0] << '\n';
            if (p == -1) continue;
            bool ok = true;
            for (int i = p; i < p + x; i++) for (int j = q; j < q + y; j++) {
                if (d[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int i = p; i < p + x; i++) for (int j = q; j < q + y; j++) d[i][j] = 1;
                if (dfs(id + 1)) return true;
                for (int i = p; i < p + x; i++) for (int j = q; j < q + y; j++) d[i][j] = 0;
            }
        }
        return false;
    };

    for (int s = 1; s < (1 << n); s++) {
        int sum = 0;
        c.clear();
        for (int i = 0; i < n; i++) if ((s >> i) & 1) {
            c.push_back(i);
            sum += a[i] * b[i];
        }
        if (sum != h * w) continue;
        d = vector<vector<int>>(h, vector<int>(w, 0));
        // cout << "s= " << s << '\n';
        do {        
            if (dfs(0)) {
                ok = true;
                break;
            }
        } while (next_permutation(c.begin(), c.end()));
    }
    cout << (ok ? "Yes" : "No") << '\n';

    return 0;
}