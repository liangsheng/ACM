use std::cmp::max;
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

    for _ in 0..(scan.next::<usize>()) {
        let n = scan.next::<i32>();
        if n % 2 == 0 {
            writeln!(out, "{} {}", n / 2, n / 2).ok();
        } else {
            let mut a = 1;
            for i in 2..n {
                if i * i > n {
                    break;
                }
                if n % i == 0 {
                    a = max(a, n / i);
                }
            }
            if a == 1 {
                writeln!(out, "{} {}", 1, n - 1).ok();
            } else {
                writeln!(out, "{} {}", a, n - a).ok();
            }
        }
    }
}