use std::cmp::{max};
use std::io::{BufWriter, stdin, stdout, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}

impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Faild read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n = scan.next::<usize>();
    let k = scan.next::<usize>();
    let d = scan.next::<i64>();
    let a: Vec<i64> = (0..n).map(|_| scan.next::<i64>()).collect::<Vec<_>>();
    let mut dp = vec![vec![vec![-1; d as usize]; k + 1]; n];
    dp[0][0][0] = 0;
    dp[0][1][(a[0] % d) as usize] = a[0];
    for i in 1..n {
        for j in 0..(k + 1) {
            for h in 0..d {
                let e = h as usize;
                dp[i][j][e] = dp[i - 1][j][e];
                if j > 0 {
                    let c = (((h - a[i]) % d + d) % d) as usize;
                    if dp[i - 1][j - 1][c] != -1 {
                        dp[i][j][e] = max(dp[i][j][e], dp[i - 1][j - 1][c] + a[i]);
                    }
                }
                // writeln!(out, "{}, {}, {}, {}", i, j, h, dp[i][j][e]).ok();
            }
        }
    }
    writeln!(out, "{}", dp[n - 1][k][0]).ok();
}