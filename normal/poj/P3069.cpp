// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int r, n;
    while (cin >> r >> n) {
        if (r == -1 && n == -1) break;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int ans = 0;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            ans++;
            int j = i;
            while (i + 1 < n && a[i + 1] - a[j] <= r) i++;
            j = i;
            while (i + 1 < n && a[i + 1] - a[j] <= r) i++;
        }
        cout << ans << '\n';
    }
    return 0;
}