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
    let m = scan.next::<usize>();
    let s: Vec<char> = scan.next::<String>().chars().collect::<Vec<_>>();
    let mut a = vec![0; n + 1];
    let mut b = vec![0; n + 1];
    let mut c = vec![0; n + 1];
    for i in 0..n {
        a[i + 1] = a[i];
        if s[i] == 'A' {
            a[i + 1] += 1;
        }
        b[i + 1] = b[i];
        if s[i] == 'B' {
            b[i + 1] += 1;
        }
        c[i + 1] = c[i];
        if s[i] == 'C' {
            c[i + 1] += 1;
        }
    }
    for _ in 0..m {
        let l = scan.next::<usize>();
        let r = scan.next::<usize>();
        let mut cnt = 0;
        if a[r] - a[l - 1] > 0 {
            cnt += 1;
        }
        if b[r] - b[l - 1] > 0 {
            cnt += 1;
        }
        if c[r] - c[l - 1] > 0 {
            cnt += 1;
        }
        writeln!(out, "{}", cnt - 1).ok();
    }
}