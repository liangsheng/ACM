#include <bits/stdc++.h>
using namespace std;

// 查找 a 中第一个大于等于 x 的下标; 如果没有, 就返回 n
int my_lower_bound(vector<int>& a, int x) {
    int n = a.size(), l = 0, r = n - 1, mid;
    if (a[r] < x) return n;  // a 中所有的数都比 x 小
    while (l != r) {
        mid = (l + r) / 2;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

// 查找 a 中第一个大于 x 的下标; 如果没有, 就返回 n
int my_upper_bound(vector<int>& a, int x) {
    int n = a.size(), l = 0, r = n - 1, mid;
    if (a[r] <= x) return n;  // a 中所有的数都不超过 x 小
    while (l != r) {
        mid = (l + r) / 2;
        if (a[mid] > x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    // 下面 2 句是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    while (cin >> x >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // 使用 vector 的 lower_bound() 和 upper_bound()
        // int l = lower_bound(a.begin(), a.end(), x) - a.begin();
        // int r = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
        // if (l >= n || a[l] > x) cout << "[-1,-1]" << '\n';
        // else cout << "[" << l + 1 << "," << r + 1 << "]" << '\n';

        // 使用自己写的 my_lower_bound() 和 my_upper_bound()
        int l = my_lower_bound(a, x), r = my_upper_bound(a, x) - 1;
        if (l >= n || a[l] > x) cout << "[-1,-1]" << '\n';
        else cout << "[" << l + 1 << "," << r + 1 << "]" << '\n';
    }
    return 0;
}