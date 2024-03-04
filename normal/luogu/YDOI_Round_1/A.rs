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

fn gcd(x: i64, y: i64) -> i64 {
    if x % y == 0 { y } else { gcd(y, x % y) }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    
    let n = scan.next::<usize>();
    let a = (0..n).map(|_| scan.next::<i64>()).collect::<Vec<_>>();
    let d = (1..n).fold(a[0], |ans, id| gcd(ans, a[id] - a[id - 1]));
    let ans = if d % 2 == 0 { d / 2 } else { -1 };
    writeln!(out, "{}", ans).ok();
}