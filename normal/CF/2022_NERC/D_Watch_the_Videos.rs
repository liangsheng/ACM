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

    let n = scan.next::<usize>();
    let m = scan.next::<u64>();
    let mut a = (0..n).map(|_| scan.next::<u64>()).collect::<Vec<_>>();
    a.sort();
    let mut ans: u64 = 0;
    let mut p: usize = 0;
    for i in (0..n).rev() {
        if i == p {
            ans += a[i] + 1;
            break;
        }
        if i < p {
            break;
        }
        if a[i] + a[p] > m {
            ans += a[i] + 1;
        } else {
            ans += a[p] + a[i];
            if p + 1 == i {
                ans += 1;
                break;
            }
            p = p + 1;
        }
    }
    writeln!(out, "{}", ans).ok();
}