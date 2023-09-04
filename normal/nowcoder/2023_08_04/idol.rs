#![allow(dead_code, unused_variables, dead_code, unused_mut)]
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

fn gao(n: i128, d: i128) -> i128 {
    let s = (d - 1) / 2;
    let num = n / 2 + 1;
    let m = num / d;
    if m == 0 {
        return num - (d + 1) / 2;
    }
    let t = s + (m - 1) * d * 2;
    let mut ans = (s + t) * m / 2;
    let q = num % d;
    if q > 0 {
        let b = m * 2;
        if q <= (d + 1) / 2 {
            ans += b * q;
        } else {
            ans += b / 2 * (d + 1) + (b + 1) * (q - (d + 1) / 2);
        }
    }
    return ans;
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n = scan.next::<i128>();
    if n <= 4 {
        writeln!(out, "0").ok();
    } else {
        let mut ans = 0;
        let m = n - n % 2;
        let mut d: i128 = 5;
        while d <= m {
            let tmp = gao(m, d);
            ans += tmp;
            d *= 5;
        }
        if n % 2 == 1 {
            d = 5;
            while d <= n + 1 {
                ans += (n + 1) / d;
                d *= 5;
            }
            let p = (n + 1) / 2;
            d = 5;
            while d <= p {
                ans -= p / d;
                d *= 5
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}