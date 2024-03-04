// https://loj.ac/s/1993650
#include<bits/stdc++.h>
class LinkCutTree
{
	private:
		struct Node{unsigned int parent,child[2],color[3],tag,rev,value;}*node;
		inline bool which(unsigned int x){return x==node[node[x].parent].child[1];}
		inline bool isroot(unsigned int x){return node[node[x].parent].child[0]!=x&&node[node[x].parent].child[1]!=x;}
		inline void pushdown(unsigned int x){
			if(node[x].rev)
			std::swap(node[x].child[0],node[x].child[1]),
			std::swap(node[node[x].child[0]].color[1],node[node[x].child[0]].color[2]),
			std::swap(node[node[x].child[1]].color[1],node[node[x].child[1]].color[2]),
			node[node[x].child[0]].rev^=1,node[node[x].child[1]].rev^=1,node[x].rev=0;
			if(node[x].tag)
			node[x].color[0]=node[x].color[1]=node[x].color[2]=node[x].tag,
			node[node[x].child[0]].tag=node[node[x].child[1]].tag=node[x].tag,
			node[x].tag=node[x].value=0;
		}
		inline void pushup(unsigned int x){
			pushdown(node[x].child[0]),pushdown(node[x].child[1]);
			node[x].value=node[node[x].child[0]].value+node[node[x].child[1]].value;
			if(node[x].child[0]){
				node[x].color[1]=node[node[x].child[0]].color[1];
				if(node[x].color[0]!=node[node[x].child[0]].color[2])++node[x].value;
			}
			else node[x].color[1]=node[x].color[0];
			if(node[x].child[1]){
				node[x].color[2]=node[node[x].child[1]].color[2];
				if(node[x].color[0]!=node[node[x].child[1]].color[1])++node[x].value;
			}
			else node[x].color[2]=node[x].color[0];
		}
		inline void rotate(unsigned int x){
			unsigned int y=node[x].parent,z=node[y].parent,k=which(x);
			if(!isroot(y))node[z].child[y==node[z].child[1]]=x;
			node[y].child[k]=node[x].child[!k],node[node[x].child[!k]].parent=y,
			node[x].child[!k]=y,node[y].parent=x,node[x].parent=z;
			pushup(y),pushup(x);
		}
		inline void update(unsigned int x){
			if(!isroot(x))update(node[x].parent);
			pushdown(x);
		}
		inline void splay(unsigned int x){
			update(x);
			for(unsigned int par;par=node[x].parent,!isroot(x);rotate(x))
			if(!isroot(par))rotate(which(par)==which(x)?par:x);
		}
		inline void access(unsigned int x){for(unsigned int y=0;x;y=x,x=node[x].parent)splay(x),node[x].child[1]=y,pushup(x);}
		inline void makeroot(unsigned int x){access(x),splay(x),node[x].rev^=1;}
	public:
		LinkCutTree(unsigned int size){node=new Node[size+1]();}
		~LinkCutTree(){delete[]node;}
		inline void setcolor(unsigned int x,unsigned int c){node[x].color[0]=node[x].color[1]=node[x].color[2]=c;}
		inline void setupd(unsigned int x,unsigned int tag){node[x].tag=tag;}
		inline unsigned int query(unsigned int x){return node[x].value;}
		inline void link(unsigned int x,unsigned int y){makeroot(x),splay(x),node[x].parent=y;}
		inline void split(unsigned int x,unsigned int y){makeroot(x),access(y),splay(y);}
};
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr),std::cout.tie(nullptr);
	unsigned int n,m;
	std::cin>>n>>m;
	LinkCutTree tree(n);
	for(unsigned int i=1,w;i<=n;++i)std::cin>>w,tree.setcolor(i,w);
	for(unsigned int i=1,u,v;i<n;++i)std::cin>>u>>v,tree.link(u,v);
	char op;
	for(unsigned int a,b,c;m--;)
	switch(std::cin>>op,op){
		case'C':std::cin>>a>>b>>c,tree.split(a,b),tree.setupd(b,c);break;
		case'Q':std::cin>>a>>b,tree.split(a,b),std::cout<<tree.query(b)+1<<'\n';break;
	}
	return 0;
}
