import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class Chimney {
	
	static long MOD = 1000000007;
	static PrintStream out = new PrintStream(System.out);
	
	public static long [][] mul(long a[][], long b[][]) {
		int i, j, k, n = a.length;
		long c[][] = new long[n][n];
		for (i = 0; i < 9; i++) Arrays.fill(c[i], 0);
		for (i = 0; i < n; i++) {
			for (k = 0; k < n; k++) {
				if (a[i][k] == 0) continue;
				for (j = 0; j < n; j++) {
					if (b[k][j] == 0) continue;
					c[i][j] += a[i][k] * b[k][j];
					c[i][j] %= MOD;
				}
			}
		}
		return c;
	}
	
	public static long [][] power(long a[][], long h) {
		int i, n = a.length;
		long c[][] = new long[n][n];
		for (i = 0; i < 9; i++) Arrays.fill(c[i], 0);
		for (i = 0; i < n; i++) c[i][i] = 1;
		while (h != 0) {
			if ((h & 1) == 1) c = mul(c, a);
			a = mul(a, a);
			h >>= 1;
		}
		return c;
	}
	
	public static int countWays(long h) {
		int i, j, k;
		long a[][] = new long[19][19], dp[][] = new long[18][18];
		for (i = 0; i < 9; i++) Arrays.fill(a[i], 0);
		a[0][1] = 4;
		a[1][2] = a[2][5] = a[3][5] = a[4][6] = a[5][6] = 2;
		a[1][3] = a[2][4] = a[6][7] = a[7][8] = a[5][9] = a[6][10] = a[7][11] = a[8][13] = 1;
		for (i = 0; i < 18; i++) {
			Arrays.fill(dp[i], 0);
			dp[i][i] = 1;
			for (j = 0; j < 18; j++) {
				for (k = 0; k < 18; k++) dp[i][k] += dp[i][j] * a[j][k];
			}
		}
		long b[][] = new long[9][9];
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) b[i][j] = dp[i][j + 9];
		}
		b = power(b, h);
		long ans = b[0][0];
		return (int) ans;
	}
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		long n;
		while (cin.hasNext()) {
			n = cin.nextLong();
			countWays(n);
		}
	}
}
