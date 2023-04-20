#include <bits/stdc++.h>
using namespace std;

string s;

bool gao() {
    int n = s.size();
    vector<int> L(n, -1);
    stack<int> Q;
    for (int i = 0; i < n; i++) {
        if (s[i] != '(' && s[i] != ')') continue;
        if (s[i] == '(') Q.push(i);
        else L[i] = Q.top(), Q.pop();
    }
    vector<bool> f(26, 0);
    stack<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') continue;
        if (s[i] >= 'a' && s[i] <= 'z') {
            int id = s[i] - 'a';
            if (f[id]) return 0;
            f[id] = 1, q.push({id, i});
        } else {
            while (!q.empty() && q.top().second >= L[i]) {
                f[q.top().first] = 0;
                q.pop();
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> s) {
        cout << (gao() ? "Yes" : "No") << '\n';
    }
    return 0;
}