// #![allow(dead_code, unused_variables, dead_code, unused_mut)]
use std::io::{BufWriter, stdin, stdout, Write};
use std::cmp::{max};

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

    let _t = scan.next::<usize>();
    for _ in 0.._t {
        let n = scan.next::<usize>();
        let s = scan.next::<String>().chars().collect::<Vec<_>>();
        let a = s.iter().filter(|x| **x == '0').count();
        let b = s.iter().filter(|x| **x == '1').count();
        let mut ans = max(1, a * b);
        let mut cnt = 1;
        for i in 1..n {
            if s[i] == s[i - 1] {
                cnt += 1;
            } else {
                cnt = 1;
            }
            ans = ans.max(cnt * cnt);
        }
        writeln!(out, "{}", ans).ok();
    }
}