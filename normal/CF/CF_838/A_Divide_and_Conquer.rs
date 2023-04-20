use std::cmp::{min};
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

    for _ in 0..scan.next::<usize>() {
        let n = scan.next::<usize>();
        let a: Vec<i32> = (0..n).map(|_| scan.next::<i32>()).collect::<Vec<_>>();
        let cnt = a.iter().sum::<i32>();
        if cnt % 2 == 0 {
            writeln!(out, "{}", 0).ok();
        } else {
            let mut ans = 1000;
            for d in a.iter() {
                let mut tmp = 0;
                let mut t = *d;
                while t != 0 && t % 2 + d % 2 != 1 {
                    tmp += 1;
                    t = t / 2;
                }
                if t % 2 + d % 2 == 1 {
                    ans = min(ans, tmp);
                }
            }
            writeln!(out, "{}", ans).ok();
        }
        
    }
}