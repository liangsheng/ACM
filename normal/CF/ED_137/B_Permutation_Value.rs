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

    let case = scan.next::<i32>();
    for _ in 0..case {
        let n = scan.next::<i32>();
        let mut a: Vec<i32> = (0..n).map(|i| i + 2).collect();
        a[0] = 1;
        a[(n as usize) - 1] = 2;
        writeln!(out, "{}", a.into_iter().map(|i| i.to_string()).collect::<Vec<_>>().join(" ")).ok();
    }
}