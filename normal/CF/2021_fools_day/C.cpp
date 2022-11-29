#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    string s;
    while (cin >> s) {
        bool flag = 1;
        for (int i = 2; i < s.size(); i++) {
            int x = s[i - 2] - 'A';
            int y = s[i - 1] - 'A';
            int z = s[i] - 'A';
            if ((x + y) % 26 != z) {
                flag = 0;
                break;
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
