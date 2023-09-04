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

    let n = scan.next::<usize>();
    let mut a = (0..n).map(|_| scan.next::<i32>()).collect::<Vec<_>>();
    a.sort();
    let mut l: usize = 0;
    let mut r: usize = n / 2 + 1;
    let mut f: i32 = 0;
    let mut b = vec![0; n];
    for i in 0..n {
        if f == 0 {
            b[i] = a[l];
            l += 1;
        } else {
            b[i] = a[r];
            r += 1;
        }
        f ^= 1;
    }
    let mut ans = true;
    let mut i: usize = 1;
    while i < n {
        if b[i] <= b[i - 1] || b[i] <= b[i + 1] {
            ans = false;
            break;
        }
        i += 2;
    }
    if ans {
        writeln!(out, "Yes").ok();
    } else {
        writeln!(out, "No").ok();
    }
}