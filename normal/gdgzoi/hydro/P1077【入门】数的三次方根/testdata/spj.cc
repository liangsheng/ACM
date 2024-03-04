#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const double EPS = 1.5E-6;

int main(int argc, char *argv[]) {
    setName("compare two doubles, maximal absolute error = %.10f", EPS);
    registerTestlibCmd(argc, argv);

	double a = ans.readDouble();
	double b = ouf.readDouble();
	if (abs(a - b) < 0.000001) {
		quitf(_ok, "answer is %.6f", a);
	} else {
		quitf(_wa, "expected %.6f, found %.6f", a, b);
	}
}