#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    while (cin >> n >> s) {
        stack<char> q;
        int y = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch != ')') {
                q.push(ch);
                if (ch == '(') y++;
            } else if (y > 0) {
                while (!q.empty() && q.top() != '(') q.pop();
                q.pop();
                y--;
            } else q.push(')');
        }
        string ans;
        while (!q.empty()) ans.push_back(q.top()), q.pop();
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
    return 0;
}