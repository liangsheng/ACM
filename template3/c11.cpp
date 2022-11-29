#include <bits/stdc++.h>
using namespace std;

typedef pair<int, vector<int> > piv;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        set<pair<int, vector<int>>> mp;
        int sum = 0;
        for(int i = 0; i < n; i++) sum += mat[i][0];
        mp.insert(make_pair(sum, vector<int>(n, 0)));
        vector<int> all;
        while(all.size() < k){
            auto [v, ind] = *mp.begin(); mp.erase(mp.begin());
            all.push_back(v);
            for(int i = 0; i < n; i++){
                if(ind[i] + 1 < m){
                    vector<int> cp = ind;
                    cp[i]++;
                    mp.insert(make_pair(v - mat[i][ind[i]] + mat[i][ind[i] + 1], cp));
                }
            }
        }
        return all[k - 1];
    }
};

int main() {
	set<piv> s;
	s.insert({-1, vector<int>(10, 0)});
	auto xx = *s.begin();
	cout << xx.first << ' ' << get<0>(xx) << '\n';
	vector<int> a(10, 10);
	map<int, int> b;
	b[1] = 2;
	b.emplace(2, 3);
	for (auto &x: b) cout << x.first << ' ' << x.second << '\n';
	for (auto &x: a) cout << x << '\n';
	auto f = [&](int a, int b) {return a > b;};
	for_each(a.begin(), a.end(), [&](int x) { cout << x + 100 << '\n'; });
	cout << f(3, 6) << '\n';
	cout << __builtin_ffs(4) << '\n';
	vector<pair<int, int> > q;
	q.push_back({1, 2});
	cout << get<0>(make_tuple(1, 2, "3")) << '\n';
	tuple<int, int, string> c;
        vector<pair<int, int>> arr;
        auto cmp = [](const pair<int, int>& x, const pair<int, int>& y) {
            if (x.first != y.first) return x.first > y.first;
            return x.second > y.second;
        };
        sort(arr.begin(), arr.end(), cmp);
	return 0;
}
