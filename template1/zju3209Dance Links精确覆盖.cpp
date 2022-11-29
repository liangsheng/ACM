#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define M 1024
#define N 512
const int V=N*M;
const int head=0;

int U[V],D[V],L[V],R[V],C[V];

int S[M],H[M];

int ans,size;

int n,m,p;

void Remove(int c)
{
	int i,j;
	L[R[c]]=L[c],R[L[c]]=R[c];
	for(i=D[c];i!=c;i=D[i]){
		for(j=R[i];j!=i;j=R[j]){
			S[C[j]]--;
			U[D[j]]=U[j];
			D[U[j]]=D[j];
		}
	}
}
void Resume(int c)
{
	int i,j;
	for(i=U[c];i!=c;i=U[i]){
		for(j=L[i];j!=i;j=L[j]){
			S[C[j]]++;
			U[D[j]]=D[U[j]]=j;
		}
	}
	L[R[c]]=R[L[c]]=c;
}

void Dance(int k)
{
	int min,i,j,c;

	if(R[head]==head){
		if(k<ans) ans=k;
		return;
	}
	for(min=M,c=0,i=R[head];i!=head;i=R[i]){
		if(S[i]<min) min=S[i],c=i;
	}
	Remove(c);
	for(i=D[c];i!=c;i=D[i]){
		for(j=R[i];j!=i;j=R[j])
			Remove(C[j]);
		Dance(k+1);
		for(j=L[i];j!=i;j=L[j])
			Resume(C[j]);
	}
    Resume(c);
}

void Link(int &r,int c)
{
	S[c]++;C[size]=c;

	U[size]=U[c];D[U[c]]=size;
	D[size]=c;U[c]=size;
	if(r==-1) 
		L[size]=R[size]=r=size;
	else{
		L[size]=L[r];R[L[r]]=size;
		R[size]=r;L[r]=size;
	}
    size++;
}

int main()
{

	int t,i,x,y;
	int xo,yo,xl,yl;

	scanf("%d",&t);

	while(t--){
		scanf("%d%d%d",&n,&m,&p);
		m*=n;n=m/n;

		for(i=0;i<=m;i++){
			S[i]=0;U[i]=D[i]=i;
			L[i+1]=i;R[i]=i+1;
		}R[m]=0;size=m+1;
		memset(H,-1,sizeof(H));
		for(i=0;i<p;i++){
			scanf("%d%d%d%d",&xo,&yo,&xl,&yl);
			for(x=xo;x<xl;x++){
				for(y=yo+1;y<=yl;y++)
					Link(H[i],x*n+y);
			}
		}
        ans=M;
		Dance(0);
		printf("%d\n",ans==M?-1:ans);
	}
	return 0;
}
