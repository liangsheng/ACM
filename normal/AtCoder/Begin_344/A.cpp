#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    string t;
    cin >> s;
    int p1 = -1, p2 = -1, n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '|') {
            if (p1 == -1) p1 = i;
            else p2 = i;
        }
    }
    for (int i = 0; i < p1; i++) t.push_back(s[i]);
    for (int i = p2 + 1; i < n; i++) t.push_back(s[i]);
    cout << t << '\n';
    return 0;
}