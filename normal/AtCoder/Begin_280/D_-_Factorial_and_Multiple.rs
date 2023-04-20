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

    let mut n = scan.next::<u64>();
    let mut l: u64 = 2;
    let mut r: u64 = n;
    let mut a: Vec<(u64, u64)> = Vec::new();
    for i in 2..n {
        if i * i > n {
            break;
        }
        let mut cnt = 0;
        while n % i == 0 {
            cnt += 1;
            n /= i;
        }
        if cnt > 0 {
            a.push((i, cnt));
        }
    }
    if n > 1 {
        a.push((n, 1));
    }
    while l != r {
        let mid = (l + r) / 2;
        let mut f: bool = true;
        // writeln!(out, "mid= {}", mid).ok();
        for it in &a {
            let mut d = it.0;
            let mut cnt = 0;
            while mid / d > 0 {
                cnt += mid / d;
                d = d * it.0;
            }
            // writeln!(out, "it.0: {}, it.1: {}, cnt: {}", it.0, it.1, cnt).ok();
            if cnt < it.1 {
                f = false;
                break;
            }
        }
        if f {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    writeln!(out, "{}", l).ok();
}