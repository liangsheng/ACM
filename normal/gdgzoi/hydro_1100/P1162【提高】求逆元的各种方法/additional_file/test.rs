// #![allow(dead_code, unused_variables, dead_code, unused_mut)]
use std::io::{BufWriter, stdin, stdout, Write};
use std::cmp::{max};

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
    let a = (0..n).map(|_| scan.next::<i32>()).collect::<Vec<_>>();
    let mut dp = vec![1; n];
    let mut ans = 1;
    for i in 1..n {
        for j in (max(0, (i as i32) - 4) as usize)..i {
            if a[i] & a[j] > 0 {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    writeln!(out, "{}", ans).ok();
}