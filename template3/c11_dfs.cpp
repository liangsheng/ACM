#include <bits/stdc++.h>
using namespace std;

// leetcode: https://leetcode.cn/contest/biweekly-contest-89/problems/create-components-with-same-value/
// liouzhou_101 的代码, rank 6
class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += nums[i];
        
        vector<vector<int>> v(n);
        for (auto& e : edges)
        {
            int x = e[0], y = e[1];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        int res = 0;
        for (int i = 2; i <= n; ++i)
            if (sum % i == 0)
            {
                int need = sum / i;
                int ok = 1;
                
                vector<int> w(n);
                
                function<void(int, int)> dfs = [&](int x, int p)
                {
                    w[x] = nums[x];
                    for (auto y : v[x])
                    {
                        if (y == p) continue;
                        dfs(y, x);
                        w[x] += w[y];
                    }
                    if (w[x] > need) ok = 0;
                    if (w[x] == need) w[x] = 0;
                };
                
                dfs(0, -1);
                if (ok)
                    res = max(res, i - 1);
            }
        
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}