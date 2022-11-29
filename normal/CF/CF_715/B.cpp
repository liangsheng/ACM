#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int T, n;
string s;

bool gao() {
    int t = 0, m = 0;
    vector<int> vt, vm;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') t++, vt.push_back(i);
        else m++, vm.push_back(i);
    }
    if (t != m * 2) return 0;
    int l = 0, r = vt.size() - 1;
    for (int i = 0; i < vm.size(); i++) {
        if (vt[l] > vm[i]) return 0;
        l++;
    }
    for (int i = vm.size() - 1; i >= 0; i--) {
        if (vt[r] < vm[i]) return 0;
        r--;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        cout << (gao() ? "YES" : "NO") << '\n';
    }
    return 0;
}