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
        let s: Vec<i32> = scan.next::<String>().chars().map(|x| x as i32 - 48).collect();
        let k = scan.next::<i32>();
        let n = s.len();
        let mut r = vec![-1; n];
        for i in (0..(n - 1)).rev() {
            if s[i]
            writeln!(out, "{}", i).ok();
        }
        writeln!(out, "{:?}, {}, {}, {:?}", s, k, n, r).ok();
    }
}