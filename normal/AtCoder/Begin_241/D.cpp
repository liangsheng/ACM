#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // multiset<int> d;
    // for (int i = 0; i < 5; i++) d.insert(10);
    // for (auto it = d.lower_bound(10); it != d.end(); it++) cout << *it << '\n';
    int n, c, k;
    LL x;
    while (cin >> n) {
        multiset<LL> a;
        while (n--) {
            cin >> c >> x;
            if (c == 1) a.insert(x);
            else {
                cin >> k;
                if (c == 2) {
                    auto it = a.upper_bound(x);
                    if (it != a.begin()) {
                        it--, k--;
                        while (k > 0) {
                            if (it == a.begin()) break;
                            it--, k--;
                        }
                    }
                    if (k > 0) cout << "-1" << '\n';
                    else cout << *it << '\n';
                } else {
                    auto it = a.lower_bound(x);
                    if (it != a.end()) {
                        k--;
                        while (k > 0) {
                            if (++it == a.end()) break;
                            k--;
                        }
                    }
                    if (k > 0) cout << "-1" << '\n';
                    else cout << *it << '\n';
                }
            } 
        }
    }
    return 0;
}