#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (cin >> s) {
        int n = s.size(), e = 0;
        vector<int> q(n);
        for (int i = 0; i < n; i++) {
            q[e++] = s[i] - 'A';
            if (e >= 3 && q[e - 3] == 0 && q[e - 2] == 1 && q[e - 1] == 2) {
                e -= 3;
            }
        }
        for (int i = 0; i < e; i++) cout << char(q[i] + 'A');
        cout << '\n';
    }
    return 0;
}