#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const double EPS = 1.5E-6;

int main(int argc, char *argv[]) {
    setName("compare two doubles, maximal absolute error = %.10f", EPS);
    registerTestlibCmd(argc, argv);

    map<int, int> input_map;
    map<int, int> user_map;
	int n, m, a;
	string s;
	n = inf.readInt();
	int x, input_sum = 0;
	for(int i = 0; i < n; i++) {
		x = inf.readInt();
		input_map[x]++;
		input_sum += x;
	}
	assert(input_sum == 2 * n);
	a = ans.readInt();
	m = ouf.readInt();
	if (a == -1) {
		if (m != -1) {
            quitf(_wa, "expected -1, found %d", m);
		} else {
            quitf(_ok, "answer is -1");
		}
	}
	if (m == -1) {
        quitf(_wa, "expected -1, found %d", m);
	}
	for (int i = 0; i < m; i++) {
		x = ouf.readInt();
		user_map[x]++;
	}
	
	long long sum = 0;
	for (auto &k : user_map) {
		sum += k.first * k.second;
		if (input_map[k.first] < k.second) {
            quitf(_wa, "Outputs are not a subset");
		} 
	}
	if (sum != n) {
        quitf(_wa, "Sum of the subset is %lld", sum);
	}
	quitf(_ok, "ok");
}