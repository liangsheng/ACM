#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  long long K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++){
    B[i] = (i + A[i]) % N;
  }
  vector<int> ord(N, -1);
  vector<long long> X(1, 0);
  int c = 0;
  int l = 0;
  int curr = 0;
  while (1){
    if (ord[curr] == -1){
      ord[curr] = X.size() - 1;
      X.push_back(X.back() + A[curr]);
      curr = B[curr];
    } else {
      c = X.size() - ord[curr] - 1;
      l = ord[curr];
      break;
    }
  }
  if (K <= l){
    cout << X[K] << endl;
  } else {
    long long CS = X[l + c] - X[l];
    cout << "c= " << c << " CS= " << CS << " " << (K - l) % c << ' ' << X[l + (K - l) % c] - X[l] << ' ' << X[l] + (K - l) / c * CS << ' ' << X[l] << '\n';
    cout << X[l] + (K - l) / c * CS + X[l + (K - l) % c] - X[l] << endl;
  }
}