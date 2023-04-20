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

    let _n = scan.next::<i32>();
    let a = scan.next::<i32>();
    let b = scan.next::<i32>();
    let c = scan.next::<i32>();
    let d = scan.next::<i32>();
    if b == 0 && c == 0 {
        if a == 0 || d == 0 {
            writeln!(out, "Yes").ok();
        } else {
            writeln!(out, "No").ok();
        }
    } else {
        let mut e = c - b;
        if e < 0 {
            e = -e;
        }
        if e <= 1 {
            writeln!(out, "Yes").ok();
        } else {
            writeln!(out, "No").ok();
        }
    }
}