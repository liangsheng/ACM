#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    string s;
    cin >> s;
    string t;
    for (int i = (int) s.size() - 1; i >= 0; i--) {
        if (s[i] != '.') t.push_back(s[i]);
        else break;
    }
    reverse(t.begin(), t.end());
    cout << t << '\n';
	return 0;
}