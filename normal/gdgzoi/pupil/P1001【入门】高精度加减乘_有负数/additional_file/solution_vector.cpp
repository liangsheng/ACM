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
        c[i] = sum % 10;        // 计算当前位
        d = sum / 10;           // 计算进位
    }
    if (d > 0) c.push_back(d);  // 如果进位部位 0, 需要添加一位
    return c;
    // 可以不用 return move(c);
    // https://www.zhihu.com/question/449991183
    // https://blog.csdn.net/weixin_53022668/article/details/122063990
    // 当返回值是 vector 时, 编译器会自己优化
}

// a >= b: 1
// a < b : 0
bool cmp(vector<int>& a, vector<int>& b) {
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = (int) a.size() - 1; i >=0 ; i--) {  // 从高位开始比较
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return true;
}

// 计算 a - b, 保证 a >= b
// 参数是 vector 的时候要传引用, 加 &
vector<int> sub(vector<int>& a, vector<int>& b) {
    vector<int> c = a;                          // 初始化答案 c = a
    for (int i = 0; i < (int) b.size(); i++) c[i] -= b[i];   // 依次将 c[i] 减 b[i]
    
    int d = 0;                  // 借位
    for (int i = 0; i < (int) a.size(); i++) {
        int sum = c[i] + d;     // sum 可能为负数
        if (sum < 0) c[i] = sum + 10, d = -1;
        else c[i] = sum, d = 0;
    }
    while (!c.empty() && c.back() == 0) c.pop_back();  // c 可能会有前导 0, 需要删除
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
    
    string A, B;
    cin >> A >> B;
    
    vector<int> a, b;
    // 将 A 倒序放到 a, a[0] 放个位
    for (int i = (int) A.size() - 1; i >= 0; i--) a.push_back(A[i] - '0');
    for (int i = (int) B.size() - 1; i >= 0; i--) b.push_back(B[i] - '0');
    
    // 加法
    vector<int> c = add(a, b);
    for (int i = (int) c.size() - 1; i >= 0; i--) cout << c[i];
    cout << '\n';
    
    // 减法
    bool is_neg = false;  // 判断答案是否是负数
    vector<int> d;
    if (cmp(a, b)) d = sub(a, b);
    else d = sub(b, a), is_neg = true;
    
    if (d.empty()) cout << 0 << '\n';  // 不能输出 -0
    else {
        if (is_neg) cout << '-';
        for (int i = (int) d.size() - 1; i >= 0; i--) cout << d[i];
        cout << '\n';
    }
    return 0;
}