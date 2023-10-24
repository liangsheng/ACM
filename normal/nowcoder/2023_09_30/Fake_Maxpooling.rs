#![allow(dead_code, unused_variables, dead_code, unused_mut)]
use std::io::{BufWriter, stdin, stdout, Write};
use std::collections::BTreeSet;
// use std::cmp::{max};

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

fn gcd(x: i32, y: i32) -> i32 {
    if x % y == 0 {
        return y;
    }
    return gcd(y, x % y);
}

fn lcm(x: i32, y: i32) -> i32 {
    return x * y / gcd(x, y);
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n = scan.next::<usize>();
    let m = scan.next::<usize>();
    let _k = scan.next::<usize>();
    let mut a = vec![vec![1; m]; n];
    for i in 0..n {
        for j in 0..m {
            a[i][j] = lcm((i + 1) as i32, (j + 1) as i32);
        }
    }

    let mut s: BTreeSet<(i32, i32)> = BTreeSet::new();
    s.insert((3, 4));
    s.insert((1, 2));

    writeln!(out, "{:?}", s.first().unwrap()).ok();
    for i in s {
        writeln!(out, "{:?}", i).ok();
    }
    writeln!(out, "{:?}", a).ok();
}