// https://www.luogu.com.cn/record/181817497
#include<bits/stdc++.h>
#define PII pair<int,int>
#define fi first
#define se second 
using namespace std;
const int N=1e5+5;
inline int read(){
    int w = 1, s = 0;
    char c = getchar();
    for (; c < '0' || c > '9'; w *= (c == '-') ? -1 : 1, c = getchar());
    for (; c >= '0' && c <= '9'; s = 10 * s + (c - '0'), c = getchar());
    return s * w;
}
int m,T,ans[N];
char s[N*20];
stack<PII> st; 
signed main(){
//	freopen("expr.in","r",stdin);
//	freopen("expr.out","w",stdout);
	scanf("%d%d%s",&m,&T,s);
	int l=0,r=m+1,i,n=strlen(s);
	for(i=0;i<n;i++){
		if(s[i]=='x'){
			i++; char op=s[i];
			i++; int val=0;
			while(s[i]>='0'&&s[i]<='9') val=val*10+s[i]-'0',i++;
			if(op=='>'){
				st.push({l,val});
				l=val+1;
			}
			else{
				st.push({val,r});
				r=val-1;
			}
		}
		else if(s[i]==':'){
			l=st.top().fi,r=st.top().se;
			st.pop();
		}
		else{
			int val=0;
			while(s[i]>='0'&&s[i]<='9') val=val*10+s[i]-'0',i++;
			i--;
			for(int j=l;j<=r;j++) ans[j]=val;
		}
	}
	while(T--){
		int x=read();
		x=min(x,m+1);
		printf("%d\n",ans[x]);
	}
	return 0;
}