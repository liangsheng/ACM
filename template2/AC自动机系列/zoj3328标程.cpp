/*
题目：Searching the String
题目来源：ZOJ 3228
题目内容或思路：
    AC自动机
    查找一些单词在串中出现的次数，其中一些可以重叠，而另一些不能重叠。
    解决的方法是记录每个单词最后出现的位置。
    此题注意优化否则很容易TLE
做题日期：2010.12.11
*/
#include<cstdio>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<vector>
#include<bitset>
#include<cmath>
#include<set>
#include<ctime>
using namespace std;

const int N = 100010;
const int M = N * 6;
const int ch = 26;
int sw[128], n;
int trie[M][ch + 1], top;
int fail[M], q[M], bg, ed;
int pnt[M];
int noverlap[N], len[N], cnt[N], cnt2[N], pos[N];
int hash[N];
char str[N];
void ins(char *s, int rank, int n){
    int rt, nxt;
    for(rt = 0; *s; rt = nxt, ++s){
        nxt = trie[rt][sw[*s]];
        if(nxt == 0){
            memset(trie[top], 0, sizeof(trie[top]));
            trie[rt][sw[*s]] = nxt = top++;
        }
    }
    if(trie[rt][ch] == 0){
        trie[rt][ch] = rank;
        len[rank] = n;
    }
    hash[rank] = trie[rt][ch];
}
bool input(){
    if(scanf("%s", str) == EOF)return false;
    scanf("%d", &n);
    char tmp[10];
    top = 1;
    memset(trie[0], 0, sizeof(trie[0]));
    memset(pos, -1, sizeof(int) * (n + 1));
    memset(cnt, 0, sizeof(int) * (n + 1));
    memset(cnt2, 0, sizeof(int) * (n + 1));
    for(int i = 1; i <= n; ++i){
        scanf("%d%s", noverlap + i, tmp);
        ins(tmp, i, strlen(tmp));
    }
    return true;
}
void makefail(){
    int u, v;
    fail[0] = bg = ed = 0;
    for(int i = 0; i < ch; ++i)
        if(q[ed] = trie[0][i])
            fail[q[ed++]] = 0;
    while(bg < ed){
        u = q[bg++];
        for(int i = 0; i < ch; ++i){
            if(v = trie[u][i]){
                q[ed++] = v;
                fail[v] = trie[fail[u]][i];
            }else
                trie[u][i] = trie[fail[u]][i];
        }
    }
}
void ac(char *s){
    for(int i = 0; i < top; ++i){
        pnt[i] = 0;
        for(int j = fail[i]; j; j = fail[j]){
            if(trie[j][ch]){
                pnt[i] = j;
                break;
            }
        }
    }
    int p = 0;
    for(int i = 0; *s; ++p, ++s){
        i = trie[i][sw[*s]];
        for(int j = i; j; j = pnt[j]){
            if(!trie[j][ch])continue;
            int t = trie[j][ch];
            cnt[t]++;
            if(p - pos[t] >= len[t]){
                cnt2[t]++;
                pos[t] = p;
            }
        }
    }
}
void solve(int cas){
    makefail();
    ac(str);
    printf("Case %d\n", cas);
    for(int i = 1; i <= n; ++i)
        if(noverlap[i])
            printf("%d\n", cnt2[hash[i]]);
        else
            printf("%d\n", cnt[hash[i]]);
    puts("");
}
int main(){
//    freopen("D:\\in.txt", "r", stdin);
    for(int i = 'a'; i <= 'z'; ++i)
        sw[i] = i - 'a';
    int cas = 1;
    while(input()){
        solve(cas++);
    }
    return 0;
}
