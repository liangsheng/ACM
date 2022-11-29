#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
set<string> s;
vector<string> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        s.clear(), ans.clear();
        for (int i = 0; i < n; i++) {
            string t;
            cin >> t;
            if (t[0] == '!') {
                if (s.count(t.substr(1, t.size() - 1))) ans.push_back(t.substr(1, t.size() - 1));
            } else {
                if (s.count("!" + t)) ans.push_back(t);
            }
            s.insert(t);
        }
        if (ans.size() == 0) puts("satisfiable");
        else cout << ans[0] << '\n';
    }
    return 0;
}