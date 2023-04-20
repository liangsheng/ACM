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
        let n = scan.next::<i32>();
        let a: Vec<i64> = (0..n).map(|_| scan.next::<i64>()).collect::<Vec<_>>();
        let x: i64 = a.iter().filter(|x| **x >= 0).sum::<i64>();
        let cx: i64 = a.iter().filter(|x| **x >= 0).count() as i64;
        let y: i64 = 0 - a.iter().filter(|x| **x < 0).sum::<i64>();
        let cy: i64 = a.iter().filter(|x| **x < 0).count() as i64;
        let ans: i64 = 2 * (x * cx + y * cy + x * cy + y * cx);
        writeln!(out, "{}", ans).ok();
    }
}