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

    let n = scan.next::<usize>();
    let mut t = scan.next::<u64>();
    let a: Vec<u64> = (0..n).map(|_| scan.next::<u64>()).collect::<Vec<_>>();
    let b = a.iter().sum::<u64>();
    t = t % b;
    for i in 0..n {
        if t < a[i] {
            writeln!(out, "{} {}", i + 1, t).ok();
            break;
        }
        t -= a[i];
    }
}