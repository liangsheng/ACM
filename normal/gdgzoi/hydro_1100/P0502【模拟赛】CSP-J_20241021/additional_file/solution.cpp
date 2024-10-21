#include <bits/stdc++.h>
using namespace std;
int n,h,w;
vector<vector<int>> a;
vector<int> x,y;
vector<int> ny;
int pda(int xi,int yj,int ha,int wa){
    if((xi+ha-1)>h || (yj+wa-1)>w) return 0;
    for(int i=xi;i<=xi+ha-1;i++){
        for(int j=yj;j<=yj+wa-1;j++){
            if(a[i][j]==1) return 0;
        }
    }
    return 1;
}
int yna(){
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(a[i][j]==0) return 0;
        }
    }
    return 1;
}
void fz(int x, int y, int h, int w, int val) {
    for (int i = x; i < x + h; i++) for (int j = y; j < y + w; j++) a[i][j] = val;
}
int fh( ){
    int yn=yna( );
    // for(int i=1;i<=h;i++){
    //     for(int j=1;j<=w;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';
    if(yn==1) return 1;
    int i, j, ok = 0;
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            if(a[i][j]==1) continue;
            ok = 1;
            break;
        }
        if (ok) break;
    }
            // cout<<"i="<<i<<" j="<<j<<'\n';
            for(int num=1;num<=n;num++){
                if(ny[num]==0) continue;
                for(int hs=0;hs<=1;hs++){
                    int ha = x[num], wa = y[num];
                    if (hs == 1) swap(ha, wa);
                    int pd=pda(i,j,ha,wa);
                    // cout<<"num="<<num<<" pd="<<pd<<" hs="<<hs<<'\n';
                    if (!pd) continue;
                    ny[num]=0;
                    fz(i, j, ha, wa, 1);
                    if (fh( )) return 1;
                    fz(i, j, ha, wa, 0);
                    ny[num]=1;
                }
            }
    return 0;
}
int main() {
    cin>>n>>h>>w;
    a=vector<vector<int>> (h+1,vector<int>(w+1,0));
    x=vector<int> (n+1,0);
    y=vector<int> (n+1,0);
    ny=vector<int>(n+1,1);
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    int z=fh();
    cout << (z ? "Yes" : "No") << '\n';
    return 0;
}