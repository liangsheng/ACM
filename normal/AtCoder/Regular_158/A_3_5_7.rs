use std::cmp::min;
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

fn gao(a: &mut Vec<i32>) -> i32 {
    a.sort();
    let x = a[1] - a[0];
    let y = a[2] - a[1];
    if x % 2 == 1 || y % 2 == 1 {
        return -1;
    }
    let z = min(x, y);
    let d = z / 2;
    a[0] += 7 * d;
    a[1] += 5 * d;
    a[2] += 3 * d;
    if a[0] == a[1] {
        let b = a[2] - a[1];
        if b % 6 > 0 {
            return -1;
        }
        return b / 6 * 2 + d;
    }
    if a[1] == a[2] {
        let b = a[1] - a[0];
        if b % 6 > 0 {
            return -1;
        }
        return b / 6 * 2 + d;        
    }
    return z;
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    for _ in 0..(scan.next::<usize>()) {
        let mut a: Vec<i32> = (0..3).map(|_| scan.next::<i32>()).collect::<Vec<_>>();
        
        writeln!(out, "{}", gao(&mut a)).ok();
    }
}