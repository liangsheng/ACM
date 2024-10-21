#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 7;
const int INPUT = 1;
const int NOT = 2;
const int OR = 3;
const int AND = 4;
const int mod = 998244353;

int n, k;
vector <int> vec[MAXN]; // vec[i] 存储了结点 i 的全部子节点 
int type[MAXN];
int TRUE[MAXN], FALSE[MAXN];

int main() {
	// freopen("king.in", "r", stdin);
	// freopen("king.out", "w", stdout); 
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		string r; cin >> r;
		if(r == "input") type[i] = INPUT;
		else {
			if(r == "not") type[i] = NOT;
			else if(r == "or") type[i] = OR;
			else type[i] = AND;
			int x; cin >> x;
			for(int j = 1, t; j <= x; j++) {
				cin >> t;
				vec[i].push_back(t);
			}
		}
	}
	for(int i = n; i >= 1; i--) {
		if(type[i] == INPUT) {
			TRUE[i] = FALSE[i] = 1;
			continue;
		}
		if(type[i] == NOT) {
			int src = vec[i][0];
			TRUE[i] = FALSE[src], FALSE[i] = TRUE[src];
			continue;
		}
		if(type[i] == OR) {
			long long mul = 1, fmul = 1;
			for(auto src: vec[i]) {
				mul = mul * ((TRUE[src] + FALSE[src]) % mod) % mod;
				fmul = fmul * FALSE[src] % mod;
			}
			FALSE[i] = fmul, TRUE[i] = ((mul - fmul) % mod + mod) % mod;
		}
		if(type[i] == AND) {
			long long mul = 1, tmul = 1;
			for(auto src: vec[i]) {
				mul = mul * ((TRUE[src] + FALSE[src]) % mod) % mod;
				tmul = tmul * TRUE[src] % mod;
			}
			TRUE[i] = tmul, FALSE[i] = ((mul - tmul) % mod + mod) % mod;
		}
	}
	cout << (k == 1? TRUE[1]: FALSE[1]) << endl;
	return 0; 
}