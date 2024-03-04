// https://www.luogu.com.cn/record/147190493
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define setw(x) cout<<fixed<<setprecision(x);
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()
#define alr(x,l,r) x.begin()+l,x.begin()+r
#define fi first
#define se second
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define show(v) for(auto it:v) cout<<it<<endl;
#define caseT int T;cin>>T;while(T--)
template<typename T1, typename T2> istream &operator>>(istream &cin, pair<T1, T2> &a) {
	return cin >> a.first >> a.second;
}
template<typename T1> istream &operator>>(istream &cin, vector<T1> &a) {
	for (auto &x : a) cin >> x;
	return cin;
}
template<typename T1, typename T2> ostream &operator<<(ostream &cout, const pair<T1, T2> &a) {
	return cout << a.first << ' ' << a.second;
}
template<typename T1, typename T2> ostream &operator<<(ostream &cout, const vector<pair<T1, T2>> &a) {
	for (auto &x : a) cout << x << '\n';
	return cout;
}
template<typename T1> ostream &operator<<(ostream &cout, const vector<T1> &a) {
	int n = a.size();
	if (!n) return cout;
	cout << a[0];
	for (int i = 1; i < n; i++) cout << ' ' << a[i];
	return cout;
}
template<typename T1, typename T2> void umin(T1 &x, T2 y) {
	if (y < x) x = y;
}
template<typename T1, typename T2> void umax(T1 &x, T2 y) {
	if (x < y) x = y;
}


typedef long long ll;
typedef pair<int, int> pii;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 1e6 + 10;

namespace IO {
	char buf[1 << 23], *p1 = buf, *p2 = buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
	void read() {} template <typename T, typename... other>
	inline void read(T &f, other &...y) {
		f = 0;
		T fu = 1;
		char c = getchar();
		while (c < '0' || c > '9') {
			if (c == '-') {
				fu = -1;
			}
			c = getchar();
		}
		while (c >= '0' && c <= '9') {
			f = (f << 3) + (f << 1) + (c & 15);
			c = getchar();
		}
		f *= fu;
		read(y...);
	}
	template <typename T>
	void print(T x, char c = 0) {
		if (x < 0) putchar('-'), x = -x;
		if (x < 10) putchar(x + 48);
		else print(x / 10), putchar(x % 10 + 48);
		if (c) putchar(c);
	}
	inline void reads(string &f) {
		string str = "";
		char ch = getchar();
		while (ch < '!' || ch > '~') ch = getchar();
		while ((ch >= '!') && (ch <= '~')) str += ch, ch = getchar();
		f = str;
	}
	void prints(string s) {
		for (int i = 0; s[i]; ++i)
			putchar(s[i]);
	}
}
using namespace IO;

int v[N], vv[N];
int a[N];

void pre_work() {}
void sol() {
	int n, l, r;
	read(n, l, r);
	rep(i, 1, n) read(a[i]);
	sort(a + 1, a + n + 1);
	if (unique(a + 1, a + n + 1) - a != n + 1) return cout << 0 << endl, void();

	rep(i, 1, n) vv[a[i]] = 1;

	rep(i, 1, a[n]) {
		rep(j, 1, n) {
			if (vv[a[j] + i]) {
				v[i] = 1;
				break;
			}
		}
	}

	int ans = 0;
	l = max(l, n);
	if (r > a[n] + 1) ans += r - a[n] - 1, r = a[n] + 1;

	for (int i = l; i <= r; i++) {
		int fl = 1;
		for (int j = i; j <= a[n]; j += i) {
			if (v[j]) {
				fl = 0;
				break;
			}
		}
		ans += fl;
	}

	cout << ans << endl;
}

int main() {

	fastio;
	setw(15);
	pre_work();

	sol();
	return 0;
}