#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,M; cin >> N >> M;
	vector<vector<int>> B(N,vector<int>(M));
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++) cin >> B[i][j];
	}
    vector<vector<int>> x(N,vector<int>(M)),y(N,vector<int>(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            x[i][j] = (B[i][j]-1)/7+1;
            y[i][j] = (B[i][j]-1)%7+1;
        }
    }
    string ans = "Yes";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(0 < i && x[i][j] != x[i-1][j]+1) ans = "No";
            if(0 < j && y[i][j] != y[i][j-1]+1) ans = "No";
        }
    }
	cout << ans << endl;
}