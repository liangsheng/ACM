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
        let mut x = vec![0_f64; 3];
        let mut y = vec![0_f64; 3];
        for i in 0..3 {
            x[i] = scan.next::<f64>();
            y[i] = scan.next::<f64>();
        }
        let a = if y[0] == y[1] || y[0] == y[2] || y[1] == y[2] {
            1
        } else {
            0
        };
        let b = if x[0] == x[1] || x[0] == x[2] || x[1] == x[2] {
            1
        } else {
            0
        };
        if a == 1 && b == 1 {
            writeln!(out, "NO").ok();
        } else {
            writeln!(out, "YES").ok();
        }
    }
}