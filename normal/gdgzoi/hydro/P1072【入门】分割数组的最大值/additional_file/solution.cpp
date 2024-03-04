#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, int k) {
    int n = a.size();
    // accumulate() 用来求和
    int l = 0, r = accumulate(a.begin(), a.end(), 0), mid;

    // 可以理解为申明另外一个函数 gao(int tmp)
    auto gao = [&](int tmp) {
        int d = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > tmp) return false;
            int sum = a[i];
            while (i + 1 < n && sum + a[i + 1] <= tmp) sum += a[++i];
            d++;
        }
        return d <= k;
    };

    // 二分枚举答案, 这里是求最大值最小, 注意边界
    while (l != r) {
        mid = (l + r) / 2;
        if (gao(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    // 下面 2 句是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(a, k) << '\n';
    }
    return 0;
}