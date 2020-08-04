#include <algorithm>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 1010;
const int mod = 1e9 + 7;

const int M = 2;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

struct matrix {
  int a[M][M];
  matrix() { REP(i, M) REP(j, M) a[i][j] = 0; }

  int* operator[] (int i) { return a[i]; }
  friend matrix operator* (matrix a, matrix b) {
    matrix r;
    REP(i, M) REP(j, M) REP(k, M)
      r[i][j] = add(r[i][j], mul(a[i][k], b[k][j]));
    return r;
  }
};

matrix power(matrix a, llint b) {
  assert(b > 0); b--;
  matrix r = a;
  while (b > 0) {
    if (b&1) r = r*a;
    a = a*a, b /= 2;
  }
  return r;
}

int main(void) {
  llint N;
  scanf("%lld", &N);

  matrix a;
  a[0][0] = 1;

  matrix b;
  b[0][0] = 3;
  b[0][1] = 1;
  b[1][0] = 4;
  b[1][1] = 2;

  if (N > 1) {
    a = a * power(b, N-1);
  }

  int ans = add(a[0][0], mul(2, a[0][1]));
  printf("%d\n", ans);
  return 0;
}
