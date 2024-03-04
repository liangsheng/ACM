#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        // vector<int> p = {0, 3, 5, 4, 2, 1};
        int x = 0;
        string c;
        for (int i = 1; i < n; i++) {
            cout << "? " << x << ' ' << x << ' ' << i << ' ' << i << '\n';
            cout.flush();
            cin >> c;
            // if (p[x] < p[i]) c = "<";
            // else if (p[x] == p[i]) c = "=";
            // else c = ">";
            if (c == "<") x = i;
        }
        int y = (x == 0 ? 1 : 0);
        vector<int> a = {y};
        for (int i = 0; i < n; i++) if (i != x) {
            cout << "? " << x << ' ' << y << ' ' << x << ' ' << i << '\n';
            cout.flush();
            cin >> c;
            // if ((p[x] | p[y]) < (p[x] | p[i])) c = "<";
            // else if ((p[x] | p[y]) == (p[x] | p[i])) c = "=";
            // else c = ">";
            if (c == "<") {
                y = i;
                a = {y};
            } else if (c == "=") a.push_back(i);
        }
        for (auto i : a) {
            cout << "? " << y << ' ' << y << ' ' << i << ' ' << i << '\n';
            cout.flush();
            cin >> c;
            // if (p[y] < p[i]) c = "<";
            // else if (p[y] == p[i]) c = "=";
            // else c = ">";
            if (c == ">") y = i;
        }
        cout << "! " << x << ' ' << y << '\n';
        // cout.flush();
    }
    return 0;
}