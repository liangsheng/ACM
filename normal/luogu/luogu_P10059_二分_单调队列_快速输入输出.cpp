#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

/*-------------------------------- 快速输入输出 beign------------------------*/
inline int read() {
    int x=0,w=0; char ch=0; while(!isdigit(ch)) w|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return w?-x:x;
}

inline void write(int x) {
    if(x<0) {
        putchar('-');
        x = -x;
    }
    if(x>9) write(x / 10);
    putchar(x % 10 + '0');
}
namespace IO{
    #ifdef LOCAL
    FILE*Fin(fopen("test.in","r")),*Fout(fopen("test.out","w"));
    #else
    FILE*Fin(stdin),*Fout(stdout);
    #endif
    class qistream{static const size_t SIZE=1<<16,BLOCK=32;FILE*fp;char buf[SIZE];int p;public:qistream(FILE*_fp=stdin):fp(_fp),p(0){fread(buf+p,1,SIZE-p,fp);}void flush(){memmove(buf,buf+p,SIZE-p),fread(buf+SIZE-p,1,p,fp),p=0;}qistream&operator>>(char&str){str=getch();while(isspace(str))str=getch();return*this;}template<class T>qistream&operator>>(T&x){x=0;p+BLOCK>=SIZE?flush():void();bool flag=false;for(;!isdigit(buf[p]);++p)flag=buf[p]=='-';for(;isdigit(buf[p]);++p)x=x*10+buf[p]-'0';x=flag?-x:x;return*this;}char getch(){return buf[p++];}qistream&operator>>(char*str){char ch=getch();while(ch<=' ')ch=getch();for(int i=0;ch>' ';++i,ch=getch())str[i]=ch;return*this;}}qcin(Fin);
    class qostream{static const size_t SIZE=1<<16,BLOCK=32;FILE*fp;char buf[SIZE];int p;public:qostream(FILE*_fp=stdout):fp(_fp),p(0){}~qostream(){fwrite(buf,1,p,fp);}void flush(){fwrite(buf,1,p,fp),p=0;}template<class T>qostream&operator<<(T x){int len=0;p+BLOCK>=SIZE?flush():void();x<0?(x=-x,buf[p++]='-'):0;do buf[p+len]=x%10+'0',x/=10,++len;while(x);for(int i=0,j=len-1;i<j;++i,--j)swap(buf[p+i],buf[p+j]);p+=len;return*this;}qostream&operator<<(char x){putch(x);return*this;}void putch(char ch){p+BLOCK>=SIZE?flush():void();buf[p++]=ch;}qostream&operator<<(const char*str){for(int i=0;str[i];++i)putch(str[i]);return*this;}}qcout(Fout);
}using namespace IO;

/*-------------------------------- 快速输入输出 end--------------------------*/

const int N = 20005, M = N * 2;
const int INF = numeric_limits<int>::max() / 2;

/*
 * luogu_P10059 Choose: https://www.luogu.com.cn/problem/P10059
 * 题意: 对于一个长度为 n 的序列 a ，定义 a 的极差表示 a 中最大值与最小值之差；
 * 你需要选出 a 的 k 个长度均为 L 的不同连续子序列；
 * 记这 k 个子序列中极差的最小值为 X 你需要求出 X 的最大值。
 * 同时，你还需要求出，在满足 X 最大的情况下 L 的最小值。
 */

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int T, n, k;
    // cin >> T;
    // T = read();
    qcin >> T;
    while (T--) {
        // cin >> n >> k;
        // n = read(), k = read();
        qcin >> n >> k;
        vector<int> a(n, 0);
        // for (int& x : a) cin >> x;
        // for (int& x : a) x = read();
        for (int& x : a) qcin >> x;

        int L = 1;
        auto gao = [&](int mid, int x) {
            int p = 0, l1 = 0, r1 = 0, l2 = 0, r2 = 0;
            int ans = (x == -1 ? -1 : 0);
            vector<int> q1(n), q2(n);
            for (int i = 0; i <= n - mid; i++) {
                while (l1 != r1 && q1[l1] < i) l1++;
                while (l2 != r2 && q2[l2] < i) l2++;
                while (p < i + mid) {
                    while (l1 != r1 && a[q1[r1 - 1]] >= a[p]) r1--;
                    q1[r1++] = p;
                    while (l2 != r2 && a[q2[r2 - 1]] <= a[p]) r2--;
                    q2[r2++] = p;
                    p++;
                }
                int y = a[q2[l2]] - a[q1[l1]];
                if (x == -1) {
                    if (ans == -1 || y < ans) ans = y;
                } else {
                    ans += (y >= x);
                }
            }
            return ans;
        };

        int x = gao(n - k + 1, -1);
        int l = 1, r = n - k + 1, mid;
        while (l != r) {
            mid = (l + r) >> 1;
            if (gao(mid, x) >= k) r = mid;
            else l = mid + 1;
        }
        // cout << x << ' ' << l << '\n';
        qcout << x << ' ' << l << '\n';
    }
    return 0; 
}