#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 7;
int n, w[MAXN];

int main() {
	// freopen("jewel.in", "r", stdin);
	// freopen("jewel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	sort(w + 1, w + n + 1);
	double ans = w[1];
	if (n >= 2) {
		ans = (w[1] + w[2]) / 2.0;
		for(int i = 3; i <= n; i++) {
			ans = (ans + w[i]) / 2.0;
		}
	}
	cout << fixed << setprecision(8) << ans << endl;
	return 0;
} 