#include <bits/stdc++.h>
using namespace std;

// 计算 a + b, 参数是 vector 的时候要传引用, 加 &
vector<int> add(vector<int>& a, vector<int>& b) {
    if (a.size() < b.size()) return add(b, a);  // 保证 a.size() >= b.size()
    vector<int> c = a;                          // 初始化答案 c = a
    for (int i = 0; i < (int) b.size(); i++) c[i] += b[i];   // 依次将 b[i] 加到 c[i]
    
    int d = 0;
    for (int i = 0; i < (int) a.size(); i++) {
        int sum = c[i] + d;
        c[i] = sum % 2;        // 计算当前位
        d = sum / 2;           // 计算进位
    }
    if (d > 0) c.push_back(d);  // 如果进位部位 0, 需要添加一位
    return c;
    // 可以不用 return move(c);
    // https://www.zhihu.com/question/449991183
    // https://blog.csdn.net/weixin_53022668/article/details/122063990
    // 当返回值是 vector 时, 编译器会自己优化
}

int main() {
    // 这两句是为了让 cin 操作更快, 不理解可以不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string A;
    cin >> A;
    
    vector<int> a, b(1, 1);
    // 将 A 倒序放到 a, a[0] 放个位
    for (int i = (int) A.size() - 1; i >= 0; i--) a.push_back(A[i] - '0');
    
    int cnt = 0;
    while (a.size() > 1) {
        if (a[0] == 0) a.erase(a.begin());  // 删除 a[0]
        else a = add(a, b);
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}