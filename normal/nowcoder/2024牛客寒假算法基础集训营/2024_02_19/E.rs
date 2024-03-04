// #![allow(dead_code, unused_variables, dead_code, unused_mut)]
use std::io::{BufWriter, stdin, stdout, Write};
use std::collections::HashMap;
use std::cmp::max;

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
    let k = scan.next::<i32>();
    let a = (0..n).map(|_| scan.next::<i32>() % k).collect::<Vec<_>>();
    
    let mut dp = vec![0; n + 1];
    let mut f: HashMap<i32, usize> = HashMap::new();
    let mut ans = 0;
    let mut now = 0;
    for i in 1..=n {
        dp[i] = dp[i - 1];
        if a[i - 1] % k == 0 {
            dp[i] = max(dp[i], dp[i - 1] + 1);
        } else {
            let d = (k - a[i - 1] + k - now) % k;
            // let x = f.get(&d).copied().unwrap_or(0);
            if let Some(x) = f.get(&d) {
                dp[i] = max(dp[i], dp[x - 1] + 1);
            }
        }
        ans = max(ans, dp[i]);
        now = (now + a[i - 1]) % k;
        let t = ((a[i - 1] - now) % k + k) % k;
        f.insert(t, i);
        
        // writeln!(out, "i= {}, now= {}, {:?}, {:?}", i, now, dp, f).ok();
    }
    writeln!(out, "{}", ans).ok();
}