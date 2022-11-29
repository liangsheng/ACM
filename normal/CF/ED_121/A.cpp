#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        sort(s.begin(), s.end());
        cout << s << '\n';
    }
    return 0;
}