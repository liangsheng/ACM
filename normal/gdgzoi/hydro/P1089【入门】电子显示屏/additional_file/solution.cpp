#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// 计算 x 需要的短线数
int f(LL x) {
	int q[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int ans = 0;
	while (x != 0) ans += q[x % 10], x /= 10;
	return ans;	
}

int gao(LL l, LL r) {
	for (LL i = l; i + 1 <= r; i++) {
        if (f(i) == f(i + 1)) return 2;
    }
	return 1;
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	LL T, l, r;
    cin >> T;
	while (T--) {
        cin >> l >> r;
        cout << gao(l, r) << '\n';
    }
	return 0;
}