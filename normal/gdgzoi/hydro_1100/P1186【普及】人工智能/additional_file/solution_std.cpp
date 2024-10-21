#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000000 + 7;

int n, p[MAXN];
char s[MAXN];

int main() {
	// freopen("fool.in", "r", stdin);
	// freopen("fool.out", "w", stdout);
	cin >> (s + 1);
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> p[i]; 
	}
	p[0] = 0, p[n] = strlen(s + 1);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int st = p[i - 1] + 1, ed = p[i];
		bool hasr = false;
		for(int j = st; j <= ed; j++) {
			if(s[j] == 'r') hasr = true;
		}
		if(hasr) ++ans;
	}
	cout << ans << endl;
	return 0;
}