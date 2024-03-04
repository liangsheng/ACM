// https://www.luogu.com.cn/record/147322433
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 400000

int i, j, k, n, m, t, l, r, res, a[N + 50], vis[N + 50], it = 1;
bitset < N + 50 > vis2, f;

namespace IO {
#ifdef LOCAL
	FILE*Fin(fopen("test.in", "r")), *Fout(fopen("test.out", "w"));
#else
	FILE*Fin(stdin), *Fout(stdout);
#endif
	class qistream {
			static const size_t SIZE = 1 << 16, BLOCK = 32;
			FILE*fp;
			char buf[SIZE];
			int p;
		public:
			qistream(FILE*_fp = stdin): fp(_fp), p(0) {
				fread(buf + p, 1, SIZE - p, fp);
			} void flush() {
				memmove(buf, buf + p, SIZE - p), fread(buf + SIZE - p, 1, p, fp), p = 0;
			} qistream&operator>>(char&str) {
				str = getch();
				while (isspace(str))str = getch();
				return*this;
			} template<class T>qistream&operator>>(T&x) {
				x = 0;
				p + BLOCK >= SIZE ? flush() : void();
				bool flag = false;
				for (; !isdigit(buf[p]); ++p)flag = buf[p] == '-';
				for (; isdigit(buf[p]); ++p)x = x * 10 + buf[p] - '0';
				x = flag ? -x : x;
				return*this;
			} char getch() {
				return buf[p++];
			} qistream&operator>>(char*str) {
				char ch = getch();
				while (ch <= ' ')ch = getch();
				for (int i = 0; ch > ' '; ++i, ch = getch())str[i] = ch;
				return*this;
			}
	} qcin(Fin);
	class qostream {
			static const size_t SIZE = 1 << 16, BLOCK = 32;
			FILE*fp;
			char buf[SIZE];
			int p;
		public:
			qostream(FILE*_fp = stdout): fp(_fp), p(0) {}~qostream() {
				fwrite(buf, 1, p, fp);
			} void flush() {
				fwrite(buf, 1, p, fp), p = 0;
			} template<class T>qostream&operator<<(T x) {
				int len = 0;
				p + BLOCK >= SIZE ? flush() : void();
				x < 0 ? (x = -x, buf[p++] = '-') : 0;
				do buf[p + len] = x % 10 + '0', x /= 10, ++len;
				while (x);
				for (int i = 0, j = len - 1; i < j; ++i, --j)swap(buf[p + i], buf[p + j]);
				p += len;
				return*this;
			} qostream&operator<<(char x) {
				putch(x);
				return*this;
			} void putch(char ch) {
				p + BLOCK >= SIZE ? flush() : void();
				buf[p++] = ch;
			} qostream&operator<<(const char*str) {
				for (int i = 0; str[i]; ++i)putch(str[i]);
				return*this;
			}
	} qcout(Fout);
} using namespace IO;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	qcin >> n >> l >> r;
	for (i = 1; i <= n; i++) {
		qcin >> a[i];
		if (vis2[a[i]]) {
			cout << 0;
			return 0;
		}
		vis2[a[i]] = 1;
	}
	vis2.reset();
	sort(a + 1, a + n + 1);

	for (i = 1; i <= min(n, 2000); i++)for (j = 1; j <= min(n, 2000); j++) {
			f[abs(a[i] - a[n - j + 1])] = 1;
		}

	for (i = max(n, l); i <= min(N, r); i++) {
		for (j = i; j <= N; j += i)if (f[j])goto aaa;
		res++;
		if (i > a[1] && i + a[1] > a[n])continue;
		while (it <= n && a[it] < i) {
			vis2[a[it]] = 1;
			it++;
		}
		for (j = n; j >= it; j--) {
			t = (a[j] % i);
			if (vis[t] == i || vis2[t]) {
				res--;
				break;
			}
			vis[t] = i;
		}
aaa:
		;
	}
	l = max(l, N + 1);
	res += max(0, r - l + 1);
	qcout << res;
}