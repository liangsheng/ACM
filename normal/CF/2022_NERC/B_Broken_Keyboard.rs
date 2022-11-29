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
        let n = scan.next::<usize>();
        let s: Vec<char> = scan.next::<String>().chars().collect();

        let mut flag = true;
        let mut i = 0;
        let mut d = 0;
        while i < s.len() {
            if d == 1 {
                if i + 1 >= n || s[i + 1] != s[i] {
                    // writeln!(out, "i= {}", i).ok();
                    flag = false;
                    break;
                }
                i += 2;
            } else {
                i += 1;
            }
            d = 1 - d;
        }
        let ans = if flag {
            "YES"
        } else {
            "NO"
        };
        writeln!(out, "{}", ans).ok();
    }
}