#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin.tie(nullptr);

	int n, m;
	while (cin >> n >> m) {
		vector<string> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sort(a[i].begin(), a[i].end());
			b[i] = a[i];
			reverse(b[i].begin(), b[i].end());
		}
		set<pair<string, int> > s;
		for (int i = 0; i < n; i++) s.insert(make_pair(b[i], i));
		for (int i = 0; i < n; i++) {
			s.erase(make_pair(b[i], i));
			s.insert(make_pair(a[i], i));

			if (s.begin()->second == i) cout << 1;
			else cout << 0;
			s.erase(make_pair(a[i], i));
			s.insert(make_pair(b[i], i));
		}
		cout << endl;
	}
	return 0;
} 