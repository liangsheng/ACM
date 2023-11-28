#include <bits/stdc++.h>
using namespace std;

vector<int> f, wv;

void init(int n) {
	f = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++) f[i] = i;
	wv = vector<int>(n + 1, 0);
}

int find(int x) {
	if (f[x] == x) return f[x];
	int fa = find(f[x]);
	wv[x] = wv[fa] ^ wv[x];
	return fa;	
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int c, T, n, m, x, y;
	string cmd;
	cin >> c >> T;
	while (T--) {
		cin >> n >> m;
		init(n + 2);
		while (m--) {
			cin >> cmd;
			if (cmd == "T") {
				
			} 
		}		
	}
	return 0;
} 