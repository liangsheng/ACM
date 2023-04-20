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

fn gao(n: i32, l1: i32, r1: i32, l2: i32, r2: i32) -> i32 {
    if l1 + l2 > n || r1 + r2 < n {
        return 0;
    }
    let d = n - l1;
    let l;
    let r;
    if d <= r2 {
        l = l1;
        r = min(l1 + d - l2, r1);
    } else {
        l = l1 + d - r2;
        r = min(l + r2 - l2, r1);
    }
    return r - l + 1;
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    for _ in 0..scan.next::<usize>() {
        let n = scan.next::<i32>();
        let l1 = scan.next::<i32>();
        let r1 = scan.next::<i32>();
        let l2 = scan.next::<i32>();
        let r2 = scan.next::<i32>();
        writeln!(out, "{}", gao(n, l1, r1, l2, r2)).ok();
    }
}