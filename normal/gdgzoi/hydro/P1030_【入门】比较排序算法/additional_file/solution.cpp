#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

/*--------------------- 选择排序, 时间复杂度 O(n^2) begin -----*/
// 将 a[l], a[l + 1], ..., a[r - 1], a[r] 排序
// select_sort(a, 1, n);
void select_sort(int* a, int l, int r) {
    for (int i = r; i > l; i--) {
        int p = l;
        for (int j = l; j <= i; j++) if (a[j] > a[p]) p = j;
        swap(a[p], a[i]);
    }
}
/*--------------------- 选择排序, 时间复杂度 O(n^2) end -------*/

/*--------------------- 冒泡排序, 时间复杂度 O(n^2) begin -----*/
// 将 a[l], a[l + 1], ..., a[r - 1], a[r] 排序
// bubble_sort(a, 1, n);
void bubble_sort(int* a, int l, int r) {
    for (int i = r; i > l; i--) {
        for (int j = l; j < i; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

/*--------------------- 冒泡排序, 时间复杂度 O(n^2) end -------*/

/*--------------------- 堆排序, 时间复杂度 O(nlog(n)) begin ------*/
void down(int* a, int p, int n) {
    while (true) {
        int x = p;
        if (p * 2 <= n && a[p * 2] > a[x]) x = p * 2;
        if (p * 2 + 1 <= n && a[p * 2 + 1] > a[x]) x = p * 2 + 1;
        if (x == p) return ;
        swap(a[p], a[x]);
        p = x;
    }
}


// 将 a[1], a[2], ..., a[n - 1], a[n] 排序
// heap_sort(a, n);
void heap_sort(int* a, int n) {
    // make_heap
    for (int i = n / 2; i >= 1; i--) down(a, i, n);

    for (int i = n; i > 1; i--) {
        swap(a[1], a[i]);
        down(a, 1, i - 1);
    }
}

/*--------------------- 堆排序, 时间复杂度 O(nlog(n)) end --------*/

/*--------------------- 归并排序, 时间复杂度 O(nlog(n)) begin ----*/
// 将 a[l], a[l + 1], ..., a[r - 1], a[r] 排序
// merge_sort(a, 1, n);
int c[N];
void merge_sort(int* a, int l, int r) {
    if (l == r) return ;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);             // 将 a[l] 到 a[mid] 排序
    merge_sort(a, mid + 1, r);         // 将 a[mid + 1] 到 a[r] 排序
    int i = l, j = mid + 1, e = 0;
    while (i <= mid && j <= r) {       // 将 2 段排好序的子数组合并
        if (a[i] < a[j]) c[e++] = a[i++];
        else c[e++] = a[j++];
    }
    while (i <= mid) c[e++] = a[i++];  // 防止最后还有一些没合并的数
    while (j <= r) c[e++] = a[j++];
    for (i = 0; i < e; i++) a[l + i] = c[i];  // 还原到 a 数组
}
/*--------------------- 归并排序, 时间复杂度 O(nlog(n)) end ------*/

/*--------------------- 快速排序, 时间复杂度 O(nlog(n)) begin ----*/
void quick_sort(int* a, int l, int r) {
    if (l >= r) return ;
    int p = a[rand() % (r - l + 1) + l];  // 随机选取基准
    // i: 当前操作的元素下标
    // a[l: j) 存储小于 p 的元素(a[l], a[l + 1], ..., a[j - 1])
    // a[j: k) 存储等于 p 的元素(a[j], a[j + 1], ..., a[k - 1])
    // a[k: r] 存储大于 p 的元素(a[k], a[k + 1], ..., a[r])
    int i = l, j = l, k = r;
    while (i <= k) {
        if (a[i] < p) swap(a[i++], a[j++]);
        else if (a[i] > p) swap(a[i], a[k--]);
        else i++;
    }
    quick_sort(a, l, j - 1);
    quick_sort(a, k + 1, r);
}
/*--------------------- 快速排序, 时间复杂度 O(nlog(n)) end ------*/

int main() {
    int n;
    int a[N];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // select_sort(a, 1, n);
    // bubble_sort(a, 1, n);
    // merge_sort(a, 1, n);        // 132ms, 1.18MB
    // quick_sort(a, 1, n);        // 132ms, 816.00KB
    // heap_sort(a, n);            // 135ms, 824.00KB
    sort(a + 1, a + n + 1);     // 125ms, 832.00KB
    for (int i = 1; i <= n - 1; i++) cout << a[i] << ' ';
    cout << a[n] << '\n';
    return 0;
}