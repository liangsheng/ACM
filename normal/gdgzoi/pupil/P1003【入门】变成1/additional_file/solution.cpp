#include <bits/stdc++.h>
using namespace std;

int main() {
    // 这两句是为了让 cin 操作更快, 不理解可以不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string A;
    cin >> A;
    
    int cnt = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] == '0') cnt++;
        else {
            if (i == 0) break;
            int j = i;
            while (i - 1 >= 0 && A[i - 1] == '1') i--;
            cnt += 1 + j - i + 1;
            if (i - 1 >= 0) A[i - 1] = '1';
        }
        // cout << "i= " << i << ", cnt= " << cnt << '\n';
        // cout << A << '\n';
    }
    cout << cnt << '\n';
    return 0;
}