package acm;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	//大整数开平方跟, 牛顿迭代法, x2 = x1 + f(x1) / f`(x1) 
	private static BigInteger sqrt(String theNumber) {
		int length = theNumber.length(), i;
		BigInteger res = BigInteger.ZERO;
		BigInteger twenty = BigInteger.valueOf(20);
		BigInteger t, x = BigInteger.ZERO, v, few = BigInteger.ZERO;
		BigInteger hg = BigInteger.valueOf(100);
		String tmpString = null;
		int pos = 2 - length % 2;
		tmpString = theNumber.substring(0, pos);
		while (true) {
			BigInteger tmp1 = BigInteger.valueOf(Integer.parseInt(tmpString));
			v = few.multiply(hg).add(tmp1);
			if (res.compareTo(BigInteger.ZERO) == 0)
				i = 9;
			else
				i = v.divide(res.multiply(twenty)).intValue();
			for (; i >= 0; i--) {
				BigInteger tmp2 = BigInteger.valueOf(i).multiply(
						BigInteger.valueOf(i));
				t = res.multiply(twenty).add(tmp2);
				if (t.compareTo(v) <= 0) {
					x = t;
					break;
				}
			}
			res = res.multiply(BigInteger.TEN).add(BigInteger.valueOf(i));
			few = v.subtract(x);
			pos++;
			if (pos > length)
				break;
			tmpString = theNumber.substring(pos - 1, ++pos);
		}
		return res;
	}
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int i, j, k, x, T, R, tt, cas = 0;
		BigDecimal r;
		BigDecimal tmp = BigDecimal.valueOf(1), t = BigDecimal.valueOf(1), hh, kk;
		String s = "1.732050807568877293527446341505872366942805253810380628055806979451933016908800037081146186757248575675626141415406703029969945094998952478811655512094373648528093231902305582067974820101084674923265015312343266903322886650672254668921837971227047131660367861588019049986537379859389467650347506576051";
		for (i = 2; i < s.length(); i++) {
			t = t.multiply(BigDecimal.valueOf(0.1));
			x = s.charAt(i) - '0';
			tmp = tmp.add(t.multiply(BigDecimal.valueOf(x)));
		}
		tmp = tmp.pow(2);
		T = cin.nextInt();
		for (k = 1; k <= T; k++) {
			R = cin.nextInt();
			r = BigDecimal.valueOf(R * R);
			System.out.println("Case " + (++cas) + ":");
			for (i = 0; i <= 2 * R; i++) {
				for (j = 0; j <= 2 * R; j++) {
					tt = (i - R) * (i - R) + (j - R) * (j - R);
					hh = BigDecimal.valueOf(tt);
					kk = hh.subtract(r);
					kk = kk.abs();
					if (kk.compareTo(tmp) == -1) {
						System.out.print("*");
					} else {
						System.out.print(" ");
					}
				}
				System.out.println();
			}
		}
	}
}
