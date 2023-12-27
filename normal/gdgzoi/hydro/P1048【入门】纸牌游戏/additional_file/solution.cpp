#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    string s;
    while (cin >> n) {
        map<string, int> q;
        map<string, int> h;
        for (int i = 0; i < n; i++) {
            cin >> s >> x;
            q[s] += x;
            h[s] = i;
        }
        int maxi = 0;
        string ans;
        for (auto it : q) {
            string name = it.first;
            int score = it.second;
            if (score > maxi || (score == maxi && h[name] < h[ans])) {
                ans = name, maxi = score;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}