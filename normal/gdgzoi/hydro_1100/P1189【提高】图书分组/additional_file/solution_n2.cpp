#include<bits/stdc++.h>
using namespace std;

int n, w[5007], m, k;
long long dp[5007];

int main() {
	cin >>n>>m>>k;
	for(int i = 1; i <= n; i++) {
		cin >>w[i];
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], dp[j - 1] + (i + j) * (i - j + 1) + abs(w[i] - w[j]) + k);
		}
	}
	cout << dp[n];
} 