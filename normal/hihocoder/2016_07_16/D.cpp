#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <memory.h>
#include <cctype>
#define MOD 998244353
#define G 3
using namespace std ;

const int MAXN = 1210 ;

inline void read(int &a) {
    a = 0;
    char c = getchar();
    while (isspace(c)) c = getchar();
    if (c == '-') c = getchar();
    do a = a * 10 + c - '0',c = getchar();
    while (isdigit(c)) ;
}
int Wg[20] ;
//int Ct[MAXN];
int f[MAXN][MAXN];
int A[MAXN << 2] ;

int g[MAXN << 2] ;
int qpow(int a,int b) {
    int res = 1,tmp = a;
    for (; b; b >>= 1, tmp = 1LL * tmp * tmp % MOD) {
        if (b & 1) res = 1LL * res * tmp % MOD ;
    }
    return res;
}

int Nx = 0 , InvN = 0;
void DFT() {
    for (int i = 0; i < Nx; i ++) if (A[i] > i) swap(g[i], g[A[i]]) ;
    for (int h = 2, p = 1; h <= Nx; p ++, h <<= 1) {
        int w0 = Wg[p];
        for (int i = 0; i < Nx; i += h) {
            int w = 1;
            for (int j = 0; j < (h >> 1); j++) {
                int u = g[i + j], t = 1LL * g[i + j + (h >> 1)] * w % MOD ;
                g[i + j] = u + t;
                if (g[i + j] >= MOD) g[i + j] -= MOD ;
                g[i + j + (h >> 1)] = u - t ;
                if (g[i + j + (h >> 1)] < 0) g[i + j + (h >> 1)] += MOD ;
                w = 1LL * w * w0 % MOD ;
            }
        }
    }
}
void IDFT() {
    for (int i = 0; i < Nx; i ++) if (A[i] > i) swap(g[i], g[A[i]]);
    for (int h = 2, p = 1; h <= Nx; p ++, h <<= 1) {
        int w0 = Wg[p];
        for (int i = 0; i < Nx; i += h) {
            int w = 1;
            for (int j = 0; j < (h >> 1); j++) {
                int u = g[i + j], t = 1LL * g[i + j + (h >> 1)] * w % MOD ;
                g[i + j] = u + t;
                if (g[i + j] >= MOD) g[i + j] -= MOD ;
                g[i + j + (h >> 1)] = u - t ;
                if (g[i + j + (h >> 1)] < 0) g[i + j + (h >> 1)] += MOD ;
                w = 1LL * w * w0 % MOD ;
            }
        }
    }
    for (int i = 1; i < (Nx >> 1); i ++) swap(g[i], g[Nx - i]) ;
    for (int i = 0; i < Nx; i ++) g[i] = 1LL * g[i] * InvN % MOD ;

}
void Init(int N = MAXN - 10 ) {
    InvN = qpow(4096, MOD - 2) ;
    //Ct[0] = Ct[1] = 1;
    for (int i = 0; i < 16; i ++) {
        Wg[i] = qpow(G, (MOD - 1) / (1 << i)) ;
    }
    Nx = 4096;
    for (int i = 0; i < Nx; i ++) {
        for (int j = 0; j < 12; j ++) {
            if ((i >> j) & 1) A[i] |= (1 << (11 - j)) ;
        }
    }
//    for (int i = 2; i <= N; i ++) {
//        for (int j = 0; j < i; j ++) {
//            Ct[i] += 1LL * Ct[j] * Ct[i - 1 - j] %  MOD ;
//            if (Ct[i] >= MOD) Ct[i] -= MOD ;
//        }
//    }
    f[0][0] = 1;
    for (int j = 1; j <= N; j ++) {
        memset(g , 0, sizeof g) ;
        for (int i = 0; i <= N; i ++) {
            g[i] = f[j - 1][i] ;
        }
        DFT() ;
        for (int i = 0; i < Nx; i ++) g[i] = 1LL * g[i] * g[i] % MOD ;
        IDFT() ;
        for (int i = 1; i <= N; i ++) f[j][i] = g[i - 1] ;
        f[j][0] = 1;
    }
}

inline void write(int x) {
    if (x >= 10) write(x / 10) ;
    putchar(x % 10 + '0');
}
int main() {
#ifdef YJQ_LOCAL
    freopen(".in","r",stdin);
#endif
    Init() ;
    int T ;
    read(T);
    while (T --) {
        int a, b, c, n, k;
        read(a), read(b), read(c), read(n), read(k) ;
        write((f[k + 1][n] - f[k][n] + MOD) % MOD) ;
        putchar(10) ;
    }
}
