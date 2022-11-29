package TaskA;

import java.math.BigInteger;
import java.util.Scanner;

public class Test {
	static final int N = 105;
	
    public static void main(String[] args) throws Exception {
    	Scanner cin = new Scanner(System.in);
    	BigInteger zero = BigInteger.ZERO;
    	BigInteger one = BigInteger.ONE;
    	int n, m;
    	int i, j, k;
    	int a[] = new int[N];
    	BigInteger dp[][] = new BigInteger[N][N];
    	while (cin.hasNext()) {
    		n = cin.nextInt();
    		m = cin.nextInt();
    		a[0] = 0;
    		for (i = 1; i <= n; i++) a[i] = cin.nextInt();
    		for (j = 0; j <= m; j++) {
    			for (k = 0; k <= n; k++) dp[j][k] = zero;
    		}
    		dp[0][0] = one;
    		for (i = 0; i < n; i++) {
    			for (j = m - 1; j >= 0; j--) for (k = 0; k <= n; k++) {
    				if (a[i + 1] > a[k]) dp[j + 1][i + 1] = dp[j + 1][i + 1].add(dp[j][k]);
    			}
    		}
    		BigInteger ans = zero;
    		for (k = 0; k <= n; k++) ans = ans.add(dp[m][k]);
    		System.out.println(ans);
    	}
    }
}
