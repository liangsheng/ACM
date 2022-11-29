#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 300005, INF = N;

int T, d, n, k;
vector<tuple<int, int, int, int>> g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cas = 0, h, s, e;
    cin >> T;
    while (T--) {
        cin >> d >> n >> k;
        g.clear();
        for (int i = 0; i < n; i++) {
            cin >> h >> s >> e;
            g.push_back({s, 0, h, i});
            g.push_back({e, 1, h, i});
        }
        sort(g.begin(), g.end());
        set<pair<int, int>> s1, s2;
        LL ans = 0, tmp = 0;
        for (auto [s, f, h, id]: g) {
            if (f == 0) {
                s1.insert({h, id}), tmp += h;
                if (s1.size() > k) {
                    auto it = s1.begin();
                    s2.insert({it->first, it->second});
                    tmp -= it->first, s1.erase(it);
                }
                ans = max(ans, tmp);
            } else {
                if (s2.count({h, id})) s2.erase({h, id});
                else {
                    s1.erase({h, id}), tmp -= h;
                    if (!s2.empty()) {
                        auto it = s2.rbegin();
                        // cout << "it: " << it->first << ' ' << it->second << '\n';
                        s1.insert({it->first, it->second}), tmp += it->first;
                        s2.erase({it->first, it->second});
                    }
                    ans = max(ans, tmp);
                }
            }
            // cout << "s= " << s << ' ' << f << ' ' << h << ' ' << id << ' ' << tmp << ' ' << ans << '\n';
        }
        cout << "Case #" << ++cas << ": " << ans << '\n';
    }
    return 0;
}