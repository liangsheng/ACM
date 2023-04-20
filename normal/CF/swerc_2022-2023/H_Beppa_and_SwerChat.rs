use std::cmp::max;
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
        let a: Vec<i32> = (0..n).map(|_| scan.next::<i32>()).collect::<Vec<_>>();
        let b: Vec<i32> = (0..n).map(|_| scan.next::<i32>()).collect::<Vec<_>>();

        let mut fb = vec![0_usize; n + 1];
        for i in 0..n {
            fb[b[i] as usize] = i + 1;
        }
        let mut ans: i32 = 0;
        let mut p: usize = 0;
        for i in 0..n {
            if fb[a[i] as usize] < p {
                ans += 1;
            }
            p = max(p, fb[a[i] as usize]);
        }
        writeln!(out, "{}", ans).ok();
    }
}