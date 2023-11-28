#include <bits/stdc++.h>
using namespace std;

int a[1000001], p[100001];

int main() {
    int n, m = 0;  // m 记录找到的众数的个数
    int cnt = 0;   // cnt 记录每个众数出现的次数
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // 排序后, 相同的数就排在一起
    sort(a, a + n);

    // 当前统计的数出现的次数, 初始化 1
    int now = 1; 
    // 从 a[1] 开始扫描
    for (int i = 1; i < n; i++) {
        // 发现一个新的数, 统计下前一个数出现的次数
        if (a[i] != a[i - 1]) {
            if (now > cnt) {
                cnt = now;
                m = 0;
                p[m++] = a[i - 1];
            } else if (now == cnt) {
                p[m++] = a[i - 1];
            }
            // 重新初始化 1
            now = 1;
        } else {
            // 和上一个数相同
            now++;
        }
    }

    // 处理最后一个数
    if (now > cnt) {
        cnt = now;
        m = 0;
        p[m++] = a[n - 1];
    } else if (now == cnt) {
        p[m++] = a[n - 1];
    }
    cout << m << '\n';
    for (int i = 0; i < m; i++) cout << p[i] << ' ';
    return 0;
}