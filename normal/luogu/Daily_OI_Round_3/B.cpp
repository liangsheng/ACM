#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, ok = 1;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (s.count(a[i])) ok = 0;
        s.insert(a[i]);
    }
    if (!ok) {
        cout << "pigeon" << '\n';
        return ;
    }
    double l = -2 * 1e9, r = 2 * 1e9;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            r = min(r, (a[i] + a[i - 1]) * 0.5 - 0.1);
        } else {
            l = max(l, (a[i] + a[i - 1]) * 0.5 + 0.1);
        }
    }
    if (l > r) cout << "pigeon" << '\n';
    else {
        cout << "lovely" << '\n';
        cout << fixed << setprecision(3) << l << '\n';
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    work();
	return 0;
}