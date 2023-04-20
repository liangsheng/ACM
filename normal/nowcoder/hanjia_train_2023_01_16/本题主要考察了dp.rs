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
    let mut m = scan.next::<i32>();
    let mut a = vec![0; n];
    a[0] = 1;
    let mut p = 0;
    m -= 1;
    while m > 0 {
        if p + 3 < n {
            a[(p + 3) as usize] = 1;
            p += 3;
            m -= 1;
        } else {
            break;
        }
    }
    p = n - 1;
    while m > 0 {
        while a[p as usize] == 1 {
            p -= 1;
        }
        a[p as usize] = 1;
        m -= 1;
    }
    let mut ans = 0;
    for i in 0..(n - 2) {
        if a[i] + a[i + 1] + a[i + 2] >= 2 {
            ans += 1;
        }
    }
    writeln!(out, "{}", ans).ok();
}