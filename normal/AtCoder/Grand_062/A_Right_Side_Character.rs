// #![allow(dead_code, unused_variables, dead_code, unused_mut)]
use std::io::{BufWriter, stdin, stdout, Write};
// use std::collections::*;
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

// type Map<K, V> = BTreeMap<K, V>;
// type Set<T> = BTreeSet<T>;
// type Deque<T> = VecDeque<T>;

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let t = scan.next::<usize>();
    for _ in 0..t {
        let _n = scan.next::<usize>();

        // https://atcoder.jp/contests/agc062/submissions/41605688
        let s = scan.next::<String>().chars().collect::<Vec<_>>();
        let p = s.iter().position(|x| *x == 'B');
        if p.map_or(false, |l| s[l..].iter().all(|x| *x == 'B')) {
            writeln!(out, "B").ok();
        } else {
            writeln!(out, "A").ok();
        }
    }
}