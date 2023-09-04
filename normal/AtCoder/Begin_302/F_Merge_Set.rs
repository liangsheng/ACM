#![allow(dead_code, unused_variables, dead_code, unused_mut)]
use std::io::{BufWriter, stdin, stdout, Write};
use std::collections::*;
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

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n = scan.next::<usize>();
    let m = scan.next::<usize>();
    let mut g = vec![vec![]; n + m];
    for i in 0..n {
        let sz = scan.next::<usize>();
        for _j in 0..sz {
            let x = scan.next::<usize>();
            g[x - 1].push((m + i, 1));
            g[m + i].push((x - 1, 0));
        }
    }

    let mut d = vec![-1; n + m];
    let mut q = Deque::new();
    q.push_back(0);
    d[0] = 0;
    while let Some(u) = q.pop_front() {
        for &(v, w) in g[u].iter() {
            let w = d[u] + w;
            if d[v] == -1 || w < d[v] {
                d[v] = w;
                if v == m - 1 {
                    break;
                }
                q.push_back(v);
            }
        }
        if d[m - 1] != -1 {
            break;
        }
    }
    let mut ans = d[m - 1];
    if ans != -1 {
        ans -= 1;
    }
    writeln!(out, "{}", ans).ok();
}