// https://contest.xinyoudui.com/contest/280/problem/1503
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);

    vector<string> a(40);
    a[0] = "";
    a[1] = "I";
    a[2] = "II";
    a[3] = "III";
    a[4] = "IV";
    a[5] = "V";
    a[6] = "VI";
    a[7] = "VII";
    a[8] = "VIII";
    a[9] = "IX";
    for (int i = 10; i < 40; i++) a[i] = "X" + a[i - 10];
    map<char, int> q;
    q['I'] = 1, q['X'] = 2, q['V'] = 2;
    vector<int> b(40, 0);
    for (int i = 0; i < 40; i++) for (char c : a[i]) b[i] += q[c];

    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 1; i < 40; i++) if (b[i] == n) ans.push_back(i);
    cout << ans.size() << '\n';
    for (int i: ans) cout << a[i] << '\n';

    return 0;
}