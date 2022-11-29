#include <bits/stdc++.h>
using namespace std;

int a, b;
vector<int> ans;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> a >> b) {
        int sum = 0;
        ans.clear();
        if (a >= b) {
            for (int i = 1; i <= a; i++) ans.push_back(i), sum += i;
            for (int i = 1; i < b; i++) ans.push_back(-i), sum -= i;
            ans.push_back(-sum);
        } else {
            for (int i = 1; i <= b; i++) ans.push_back(-i), sum -= i;
            for (int i = 1; i < a; i++) ans.push_back(i), sum += i;
            ans.push_back(-sum);            
        }
        for (int i = 1; i < a + b; i++) cout << ans[i - 1] << ' ';
        cout << ans[a + b - 1] << '\n';
    }
    return 0;
}