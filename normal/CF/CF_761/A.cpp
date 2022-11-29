#include <bits/stdc++.h>
using namespace std;

int T;
string a, b;
int ch[26];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> a >> b;
        memset(ch, 0, sizeof(ch));
        for (int i = 0; i < a.size(); i++) ch[a[i] - 'a']++;
        string ans;
        if (ch[0] == 0 || ch[1] == 0 || ch[2] == 0) {
            sort(a.begin(), a.end());
            cout << a << '\n';
            continue;
        }
        if (b == "abc") {
            for (int i = 0; i < ch[0]; i++) ans.push_back('a');
            for (int i = 0; i < ch[2]; i++) ans.push_back('c');
            for (int i = 0; i < ch[1]; i++) ans.push_back('b');
        } else {
            for (int i = 0; i < ch[0]; i++) ans.push_back('a');
            for (int i = 0; i < ch[1]; i++) ans.push_back('b');
            for (int i = 0; i < ch[2]; i++) ans.push_back('c');
        }
        for (int i = 3; i < 26; i++) for (int j = 0; j < ch[i]; j++) ans.push_back('a' + i);
        cout << ans << '\n';
    }
    return 0;
}
