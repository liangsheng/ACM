#include <stdio.h>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std ;

typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )

LL n , k , mod , l ;

struct Matrix {
	LL mat[2][2] ;
	Matrix () {
		clr ( mat , 0 ) ;
	}
	LL* operator [] ( const int idx ) {
		return mat[idx] ;
	}
	Matrix operator * ( Matrix& a ) const {
		Matrix c ;
		for ( int i = 0 ; i < 2 ; ++ i ) {
			for ( int j = 0 ; j < 2 ; ++ j ) {
				for ( int k = 0 ; k < 2 ; ++ k ) {
					c[i][j] += mat[i][k] * a[k][j] ;
				}
				c[i][j] %= mod ;
			}
		}
		return c ;
	}
} ;

Matrix Fib ;

Matrix pow ( Matrix a , LL n ) {
	Matrix res , tmp = a ;
	res[0][0] = res[1][1] = 1 ;
	while ( n ) {
		if ( n & 1 ) res = res * tmp ;
		tmp = tmp * tmp ;
		n >>= 1 ;
	}
	return res ;
}

LL pow ( LL a , LL n ) {
	LL res = 1 , tmp = a ;
	while ( n ) {
		if ( n & 1 ) res = res * tmp % mod ;
		tmp = tmp * tmp % mod ;
		n >>= 1 ;
	}
	return res ;
}

void solve () {
	if ( l <= 62 && k >= ( 1LL << l ) ) {
		printf ( "0\n" ) ;
		return ;
	}
	LL t1 = pow ( Fib , n + 1 )[0][0] % mod , t2 = ( pow ( 2LL , n ) - t1 + mod ) % mod ;
	LL ans = 1 ;
	for ( int i = 0 ; i < l ; ++ i ) {
		if ( k & 1 ) ans = ans * t2 % mod ;
		else ans = ans * t1 % mod ;
		k >>= 1 ;
	}
	printf ( "%I64d\n" , ans % mod ) ;
}

int main () {
	Fib[0][0] = Fib[0][1] = Fib[1][0] = 1 ;
	while ( ~scanf ( "%I64d%I64d%I64d%I64d" , &n , &k , &l , &mod ) ) solve () ;
	return 0 ;
}
