#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n, k;
    while (cin >> n >> k) {
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.begin() + k);
        for (int i = 0; i < k; i++) cout << a[i] << '\n';
    }
    return 0;
}