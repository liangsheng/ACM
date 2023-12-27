#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const double EPS = 1.5E-6;

int main(int argc, char *argv[]) {
    setName("compare two doubles, maximal absolute error = %.10f", EPS);
    registerTestlibCmd(argc, argv);

	int n = inf.readInt();
	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) a[i] = inf.readInt();
	for (int i = 0; i < n; i++) b[i] = ans.readInt();
	for (int i = 0; i < n; i++) c[i] = ouf.readInt();

	int db = abs(b[0] - b[n - 1]);
	for (int i = 1; i < n; i++) db = max(db, abs(b[i] - b[i - 1]));
	int dc = abs(c[0] - c[n - 1]);
	for (int i = 1; i < n; i++) dc = max(dc, abs(c[i] - c[i - 1]));

	sort(a.begin(), a.end());
	sort(c.begin(), c.end());
	if (a != c) {
		quitf(_wa, "array changed!");
	}
	if (dc != db) {
		quitf(_wa, "expected %d, found %d", db, dc);
	}
	quitf(_ok, "answer is %d", db);
}