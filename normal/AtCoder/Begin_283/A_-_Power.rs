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

    let a = scan.next::<i32>();
    let b = scan.next::<i32>();
    let mut ans = 1;
    for _ in 0..b {
        ans *= a;
    }
    writeln!(out, "{}", ans).ok();
}