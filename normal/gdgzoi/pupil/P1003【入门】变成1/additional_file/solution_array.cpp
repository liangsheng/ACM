#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

// 将长度为 la 的大整数 a, 和长度为 lb 的大整数 b 相加
// 结果存放在长度为 lc 的大整数 c 中
void add(int* a, int la, int* b, int lb, int* c, int& lc) {
    lc = max(la, lb);
    int t = 0;  // 进位情况
    for (int i = 0; i < lc; i++) {
        c[i] = t;
        if (i < la) c[i] += a[i];
        if (i < lb) c[i] += b[i];
        t = c[i] / 2;     // 进位
        c[i] = c[i] % 2;  // 当前数
    }
    if (t > 0) c[lc++] = t;  // t > 0 时需要加一位
}

int main() {
    
    string A;
    cin >> A;
    
    int cnt = 0, la = 0, lb = 1, lc = 0;
    int a[N], b[1] = {1}, c[N];
    for (int i = (int) A.size() - 1; i >= 0; i--) a[la++] = A[i] - '0';
    while (la > 1) {
        if (a[0] == 1) {
            cnt++;
            add(a, la, b, lb, c, lc);
            for (int i = 0; i < lc; i++) a[i] = c[i];
            la = lc;
        }
        cnt++;
        for (int i = 0; i < la - 1; i++) a[i] = a[i + 1];
        la--;
    }

    cout << cnt << '\n';
    return 0;
}