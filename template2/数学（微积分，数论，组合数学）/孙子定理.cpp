#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 100;
int nn, a[MAXN], n[MAXN];

int egcd(int a, int b, int &x, int &y) {
    int d;
    if (b == 0) {
        x = 1; y = 0;
        return a;
    } else {
        d = egcd(b, a%b, y, x);
        y -= a/b*x;
        return d;
    }
}

int lmes() {
    int i, tm=1, mf, y, ret=0, m;
    for (i=0; i<nn; i++) tm *= n[i];
    for (i=0; i<nn; i++) {
        m = tm/n[i];
        egcd(m, n[i], mf, y);
        ret += (a[i]*m*(mf%n[i]))%tm;
    }
    return (ret+tm)%tm;
}

int main() {
    a[0] = 4; a[1] = 5;
    n[0] = 5; n[1] = 11;
    nn = 2;
    printf("%d\n", lmes());
    return 0;
}
