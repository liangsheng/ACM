#include <bits/stdc++.h>

using namespace std;

#define lep(i, l, r) for(int i = (l); i <= (r); i ++)
#define rep(i, l, r) for(int i = (l); i >= (r); i --)
using i64 = long long;

const int N = 1e5 + 5;
const int P = 998244353;

int n, m;
i64 k;
int w[N];
i64 lstdp[N];
i64 dp[N];
int lstpos[N];
i64 f[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	lep (i, 1, n) cin >> w[i];

	memset(lstdp, 0x3f, sizeof (lstdp));
	memset(dp, 0x3f, sizeof (dp));
    //lep (W, 0, 1e3) lstdp[W] = 0, lstpos[W] = 0;
	lstdp[w[1]] = 0;
	dp[0] = 0;
	dp[1] = dp[0] + 2 + k; 
	lep (r, 2, n) {
		i64 minv = LONG_LONG_MAX;
		if (dp[r - 1] - 1ll * r * r + r < lstdp[w[r]]) {
			lstdp[w[r]] = dp[r - 1] - 1ll * r * r + r;
			lstpos[w[r]] = r;
		}
		lep (W, 1, m) {
			minv = min(minv, lstdp[W] + 1ll * r * r + r + abs(w[r] - W) + k);
		}
        // - l * l + l + r * r + r
		dp[r] = minv;
		
		
		if (r == n) {
			cout << minv << endl;
			return 0;
		}
	}

	return 0;
}