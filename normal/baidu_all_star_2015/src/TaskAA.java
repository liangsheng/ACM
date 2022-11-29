import java.util.Scanner;

/**
 * Created by Administrator on 2015/5/23.
 */
public class TaskAA {
    static final int MODULO = (int) (1e9 + 7);

    public static void main(String[] args)  {
        Scanner cin = new Scanner(System.in);
        int dp[] = new int[1000005];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= 1000000; i++) {
            dp[i] = (int) ((long) dp[i - 1] + (long) (i - 1) * dp[i - 2] % MODULO) % MODULO;
        }
        int T = cin.nextInt();
        for (int cas = 1; cas <= T; cas++) {
            int n = cin.nextInt();
            System.out.printf("Case #%d:\n%d\n", cas, dp[n]);
        }
    }
}
