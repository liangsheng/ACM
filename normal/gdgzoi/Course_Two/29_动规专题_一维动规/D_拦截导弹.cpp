#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    // 这两句话是为了让 cin 和 cout 操作更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    vector<int> a;
    int d;
    for (int i = 0; i < s.size(); i++) {
        d = s[i] - '0';
        while (i + 1 < s.size() && s[i + 1] != ' ') {
            i++;
            d = d * 10 + s[i] - '0';
        }
        a.push_back(d);
        i++;
    }
    int n = a.size();
    vector<int> dp(n, INF);
    for (int i = n - 1; i >= 0; i--) {
        *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin() << '\n';

    vector<int> b;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        if (it == b.end()) b.push_back(a[i]);
        else *it = a[i];
    }
    cout << b.size() << '\n';
    return 0;
}