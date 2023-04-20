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
    let n = s.len();
    let mut ans = 1;
    let mut i = 1;
    while i < n {
        if s[i] != '0' {
            ans += 1;
            i += 1;
        } else {
            if i + 1 < n && s[i + 1] == '0' {
                ans += 1;
                i += 2;
            } else {
                ans += 1;
                i += 1;
            }
        }
    }
    writeln!(out, "{}", ans).ok();
}