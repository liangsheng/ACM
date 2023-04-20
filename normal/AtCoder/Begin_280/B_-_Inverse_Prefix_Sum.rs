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
    let s: Vec<i64> = (0..n).map(|_| scan.next::<i64>()).collect();
    let mut a = vec![0_i64; n];
    let mut now: i64 = s[0];
    a[0] = s[0];
    for i in 1..n {
        a[i] = s[i] - now;
        now += a[i];
    }
    let ans = a.into_iter().map(|i| i.to_string()).collect::<Vec<_>>().join(" ");
    writeln!(out, "{}", ans).ok();
}