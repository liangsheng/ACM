#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n == 2) {
            cout << a[0] << ' ' << a[1] << endl;
            continue;
        }
        sort(a.begin(), a.end());
        vector<int> b;
        int i = 0;
        for (; i < n; i += 2) b.push_back(a[i]);
        if (n % 2 == 0) i = n - 1;
        else i = n - 2;
        for (; i > 0; i -= 2) b.push_back(a[i]);
        for (i = 0; i < n - 1; i++) cout << b[i] << ' ';
        cout << b[n - 1] << '\n';
    }
    return 0;
}