#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string s;
            for (int k = 1; k <= i; k++) s.push_back('(');
            for (int k = 1; k <= i; k++) s.push_back(')');
            for (int k = i + 1; k <= n; k++) s += "()";
            cout << s << '\n';
        }
    }
    return 0;
}
