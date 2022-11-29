use std::cmp::min;
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
    let mut ans: u64 = 0;
    let mut mini: u64 = std::u64::MAX;
    for i in 0..n {
        for j in 0..n {
            let x = scan.next::<u64>();
            ans += x;
            if i + j == n - 1 {
                mini = min(mini, x);
            }
        }
    }
    ans -= mini;
    writeln!(out, "{}", ans).ok();
}