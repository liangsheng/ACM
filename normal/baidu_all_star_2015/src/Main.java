import java.io.*;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        InputStream inputStream = System.in;
        //OutputStream outputStream = System.out;
        OutputStream outputStream = new FileOutputStream("out.txt");
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    static final int MODULO = (int) (1e9 + 7);

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int T = in.nextInt(), cas;
        int dp[] = new int[1000005];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= 1000000; i++) {
            dp[i] = (int) ((long) dp[i - 1] + (long) (i - 1) * dp[i - 2] % MODULO) % MODULO;
        }
        for (cas = 1; cas <= T; cas++) {
            int n = in.nextInt();
            out.printf("Case #%d:%n%d%n", cas, dp[n]);
        }
    }

    private int inv(int x) {
        if (x == 1) return 1;
        return pow(x, MODULO - 2);
    }

    private int pow(int x, int k) {
        if (k == 0) return 1;
        if (k % 2 == 0) return pow((int) (x * (long) x % MODULO), k / 2);
        return (int) (x * (long) pow(x, k - 1) % MODULO);
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}
