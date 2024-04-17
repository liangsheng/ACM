#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

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

int main() {
    int la = 0, lb = 0, lc = 0;
    int a[N], b[N], c[N];
    
    string A, B;
    cin >> A >> B;

    // 倒过来存, a[0] 放个位
    for (int i = (int) A.size() - 1; i >= 0; i--) a[la++] = A[i] - '0';
    for (int i = (int) B.size() - 1; i >= 0; i--) b[lb++] = B[i] - '0';
    
    // 加法
    add(a, la, b, lb, c, lc);
    for (int i = lc - 1; i >= 0; i--) cout << c[i];
    cout << '\n';

    // 减法
    bool is_neg = false;  // 判断答案是否是负数
    if (cmp(a, la, b, lb)) sub(a, la, b, lb, c, lc);
    else sub(b, lb, a, la, c, lc), is_neg = true;
    
    if (lc == 0) cout << 0 << '\n';  // 不能输出 -0
    else {
        if (is_neg) cout << '-';
        for (int i = lc - 1; i >= 0; i--) cout << c[i];
        cout << '\n';
    }
    
    return 0;
}