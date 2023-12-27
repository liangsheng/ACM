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

fn gcd(x: i32, y: i32) -> i32 {
    if x % y == 0 {
        return y;
    }
    return gcd(y, x % y);
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    for _ in 0..scan.next::<usize>() {
        let a = scan.next::<i32>();
        let b = scan.next::<i32>();
        let d = gcd(a, b);
        writeln!(out, "{}", a - d).ok();
    }
}