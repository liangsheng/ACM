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

    let s: Vec<char> = scan.next::<String>().chars().collect::<Vec<_>>();
    let t: Vec<char> = scan.next::<String>().chars().collect::<Vec<_>>();

    let mut ans = s.len() + 1;
    for i in 0..s.len() {
        if s[i] != t[i] {
            ans = i + 1;
            break;
        }
    }
    writeln!(out, "{}", ans).ok();
}