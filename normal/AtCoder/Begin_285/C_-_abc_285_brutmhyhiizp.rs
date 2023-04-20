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

    let s = scan.next::<String>().chars().collect::<Vec<_>>();
    let n = s.len();
    let mut ans: u64 = 0;
    let mut now: u64 = 1;
    for _i in 1..n {
        now = now * 26;
        ans += now;
    }
    for i in 0..n {
        ans += (((s[i] as u8) - ('A' as u8)) as u64)* now;
        now /= 26;
    }
    writeln!(out, "{}", ans + 1).ok();
}