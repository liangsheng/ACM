#include <bits/stdc++.h>
using namespace std;

// C++ 自带 sort 函数
// 但如果程序中自己实现了 sort 函数, 就会执行自己写的 sort 函数, 而不会执行 C++ 的 sort 函数
// 注意: 传入的是指针类型, 会直接修改数组的值
// 数组实际存放在 l, l + 1, ..., r - 1(包含 l, 不包含 r)
void sort(int* l, int* r) {
    int n = r - l;  // 数组长度
    for (int k = n - 1; k >= 1; k--) {
        int p = 0;
        for (int i = 0; i <= k; i++) {
            if (l[i] > l[p]) p = i;
        }
        swap(l[p], l[k]);
    }
}

void sort(int* a, int n) {
    for (int k = n - 1; k >= 1; k--) {
        int p = 0;
        for (int i = 0; i <= k; i++) {
            if (l[i] > l[p]) p = i;
        }
        swap(l[p], l[k]);
    }
}

int main() {
    int n;
    int a[1005];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    cout << "数组修改前: " << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
    sort(a, a + n);

    cout << "数组修改后: " << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}