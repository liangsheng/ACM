#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;

struct Node {
    int x, y, z;
    Node() {}
    Node(int X, int Y, int Z): x(X), y(Y), z(Z) {}
    bool operator <(const Node& a) const {
        if (x != a.x) return x < a.x;
        if (y != a.y) return y < a.y;
        return z < a.z;
    }

    bool operator ==(const Node& a) const {
        return x == a.x && y == a.y && z == a.z;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> ch(26, -1);
    ch['i' - 26] = 0, ch['n' - 26] = 1, ch['w' - 26] = 2;
    vector<char> fc(3);
    fc[0] = 'i', fc[1] = 'n', fc[2] = 'w';
    int T, n;
    string s;
    cin >> T;
    vector<int> gg = {1, 2, 3};
    if (gg == {1, 2, 3}) cout << "FUCL" << '\n';
    while (T--) {
        map<Node, queue<int>> q;
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3 - i; j++) {
            q[Node(i, j, 3 - i - j)] = queue<int>();
        }
        vector<vector<int>> a(n + 1, vector<int>(3, 0));
        for (int i = 1; i <= n; i++) {
            cin >> s;
            for (int j = 0; j < 3; j++) a[i][ch[s[j]]]++;
            q[Node(a[i][0], a[i][1], a[i][2])].push(i);
        }
        int ans = 0, p = 0;
        vector<vector<int>> res;
        // while (p < n) {
        //     if (a[p][0] == 1 && a[p][1] == 1 && a[p][2] == 1) p++;
        //     else {
        //         Node t = Node(a[p][0], a[p][1], a[p][2]);
        //         if (t.x == 2 && t.y == 0 && t.z == 1) {
        //         }
        //     }
        // }
    }
    return 0;
}