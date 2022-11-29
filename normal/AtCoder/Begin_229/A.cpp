#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    string s1, s2;
    while (cin >> s1 >> s2) {
        if (s1 == "#." && s2 == ".#") {
            cout << "No" << '\n';
            continue;            
        }
        if (s1 == ".#" && s2 == "#.") {
            cout << "No" << '\n';
            continue;            
        }
        cout << "Yes" << '\n';
    }
    return 0;
}