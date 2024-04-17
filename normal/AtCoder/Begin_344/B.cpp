#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    vector<int> a;
    while (cin >> x) a.push_back(x);
    int n = a.size();
    for (int i = n - 1; i >= 0; i--) cout << a[i] << '\n';
    return 0;
}