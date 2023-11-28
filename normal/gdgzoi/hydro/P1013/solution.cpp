#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int a[5005];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    // 选择排序进行 n - 1 轮, 每轮找到最大的数放在数组后面
    for (int k = n - 1; k >= 1; k--) {
        // p 用来存储本轮最大的数的位置
        int p = 0;
        for (int i = 0; i <= k; i++) if (a[i] > a[p]) p = i;
        // 最大的数放到数组后面
        // C++ 系统函数 swap(), 用于交换两个数的值
        swap(a[p], a[k]);
    }
    
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}