#include <bits/stdc++.h>
using namespace std;

typedef pair<int, vector<int> > piv;

int main() {

	set<piv> q;
	q.insert({-1, vector<int>(10, 0)});
	auto [x, y] = *q.begin();
	cout << x << '\n';
	for (auto &i: y) cout << i << '\n';
	return 0;
}
