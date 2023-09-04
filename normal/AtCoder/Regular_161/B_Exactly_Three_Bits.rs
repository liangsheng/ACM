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
        let mut n = scan.next::<i64>();
        if n < 7 {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut a = vec![];
        while n != 0 {
            a.push(n & 1);
            n >>= 1;
        }
        a.reverse();
        let m = a.len();
        let mut now = 0;
        let mut p = m;
        for i in 0..m {
            now += a[i];
            if now == 3 {
                p = i;
                for j in (p + 1)..m {
                    a[j] = 0;
                }
                break;
            }
        }
        if p == m {
            for i in (0..m).rev() {
                if a[i] == 1 {
                    a[i] = 0;
                    now -= 1;
                    // writeln!(out, "i= {}, {}", i, m - (i as i64) - 1).ok();
                    if (m - i - 1) as i64 + now >= 3 {
                        for j in 0..((3 - now) as usize) {
                            a[i + j + 1] = 1;
                        }
                        break;
                    }
                }
            }
        }
        let mut ans: i64 = 0;
        for i in 0..m {
            ans = ans * 2 + a[i];
        }
        writeln!(out, "{}", ans).ok();
    }
}