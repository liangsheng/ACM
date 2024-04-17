#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    set<string> a;
    int n = s.size();
    for (int k = 1; k <= n; k++) for (int i = 0; i + k <= n ; i++) {
        a.insert(s.substr(i, k));
    }
    cout << a.size() << '\n';
    return 0;
}