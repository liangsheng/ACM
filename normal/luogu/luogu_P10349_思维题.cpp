#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n + 2, 0);
    int j = n + 1;
    for (int i = 1; i <= n; i++) if (s[i - 1] == 'P') {
        j = i;
        break;
    }
    for (int i = j + 1; i <= n; i++) if (s[i - 1] == 'L') {
        swap(s[i - 1], s[j - 1]);
        a[j] += 1, a[j + 1] -= 1;
        a[i] += 1, a[i + 1] -= 1;
        if (i - j > 1) a[j + 1] += 2, a[i] -= 2;
        // cout << "j= " << j << ", i= " << i << '\n';
        // cout << s << '\n';
        j++;
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        cout << a[i] << " \n"[i == n];
    }
    return 0;
}