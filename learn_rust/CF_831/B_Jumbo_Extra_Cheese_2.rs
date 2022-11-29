#[allow(unused_imports)]
use std::cmp::{min, max};
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

    for _ in 0..scan.next() {
        let n: usize = scan.next();
        let mut p = (0..n).map(|_| {
            let a = scan.next::<u64>();
            let b = scan.next::<u64>();
            (min(a, b), max(a, b))
        }).collect::<Vec<_>>();
        p.sort_by_key(|x| x.1);
        let mut ans = p[n - 1].1 + p.iter().fold(0, |acc, x| acc + x.0);
        ans *= 2;
        writeln!(out, "{}", ans).ok();
    }
}