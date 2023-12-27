#include <bits/stdc++.h>
using namespace std;

//BFFFB    0 2 4  [0, 2, 4, n + 1] 
//BFFFFB   1 3 5  [1, 3, 5, n + 1]
//BFFFE    1 3    [1, 3, n]
//BFFFFE   0 2 4  [0, 2, n]
//
//FFFF     0, 1   [0, 1, n - 1]
//BFFFF    0, 1,  [0, 1, n]

// 1 2 3, l = 1, r = 3, d = 1
// 2 4 6
// l = 3, r = 9, d = 1

int main() {
	int n;
	string s;
	while (cin >> n >> s) {
		int L = 0, R = 0, D = 2, l, r, d, ans = 0;
		for (int i = 1; i < n; i++) if (s[i] != 'F' && s[i] == s[i - 1]) ans++;
		for (int i = 0; i < n; i++) {
			if (s[i] != 'F') continue;
			int j = i;
			while (i + 1 < n && s[i + 1] == 'F') i++;
			
			int m = i - j + 1;
			if (j == 0 && i == n - 1) l = 0, r = m - 1, d = 1;
			else if (j == 0 || i == n - 1) l = 0, r = m, d = 1;
			else {
				d = 2;
				if (s[j - 1] == s[i + 1]) l = !(m % 2), r = m + 1;
				else l = m % 2, r = m;
			}
			L += l, R += r, D = min(D, d);
//			printf("i= %d, L= %d, R= %d, D= %d\n", i, L, R, D);
		}
		cout << (R - L) / D + 1 << '\n';
		for (int i = L; i <= R; i += D) cout << ans + i << '\n';
	}
	return 0;
}