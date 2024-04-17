#include <bits/stdc++.h>
using namespace std;

// 将长度为 la 的大整数 a, 和长度为 lb 的大整数 b 相加
// 结果存放在长度为 lc 的大整数 c 中
void add(int* a, int la, int* b, int lb, int* c, int& lc) {
    lc = max(la, lb);
    int t = 0;  // 进位情况
    for (int i = 0; i < lc; i++) {
        c[i] = t;
        if (i < la) c[i] += a[i];
        if (i < lb) c[i] += b[i];
        t = c[i] / 10;     // 进位
        c[i] = c[i] % 10;  // 当前数
    }
    if (t > 0) c[lc++] = t;  // t > 0 时需要加一位
}

// a >= b: 1
// a < b : 0
bool cmp(int* a, int la, int* b, int lb) {
    if (la != lb) return la > lb;
    for (int i = la - 1; i >= 0 ; i--) {  // 从高位开始比较
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return true;
}

// 计算 a - b, 保证 a >= b
void sub(int* a, int la, int* b, int lb, int* c, int& lc) {
    lc = la;
    int t = 0;                             // 借位
    for (int i = 0; i < lc; i++) {
        c[i] = a[i] + t;
        if (i < lb) c[i] -= b[i];
        if (c[i] < 0) t = -1, c[i] += 10;  // 借位
        else t = 0;
    }
    while (lc > 0 && c[lc - 1] == 0) lc--;    // 删除前导 0
}

const int N = 305, LEN = 105;

int len[N][N];
int a[N][N][LEN];

int main() {
    
    len[0][0] = 1, a[0][0][0] = 1;
    for (int i = 1; i <= 300; i++) {
        len[i][0] = 1, a[i][0][0] = 1;
        len[i][i] = 1, a[i][i][0] = 1;
        for (int j = 1; j < i; j++) {
            add(a[i - 1][j], len[i - 1][j], a[i - 1][j - 1], len[i - 1][j - 1], a[i][j], len[i][j]);
        }
    }

    int n, m;
    cin >> n >> m;
    for (int i = len[n][m] - 1; i >= 0; i--) cout << a[n][m][i];
    cout << '\n';
    
    return 0;
}