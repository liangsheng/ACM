#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n;
    LL now = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        now += a[i];
        if (now < 0) now = 0; 
    }
    cout << now << '\n';
	return 0;
}