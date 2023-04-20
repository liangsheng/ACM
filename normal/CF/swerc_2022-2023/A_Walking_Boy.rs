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

    for _ in 0..(scan.next::<usize>()) {
        let n = scan.next::<usize>();
        let mut a: Vec<i32> = (0..n).map(|_| scan.next::<i32>()).collect::<Vec<_>>();
        a.insert(0, 0);
        a.push(1440);
        let mut f = 0;
        let mut c = 0;
        for i in 0..(n + 1) {
            if a[i + 1] - a[i] >= 240 {
                f = 1;
                break;
            }
            if a[i + 1] - a[i] >= 120 {
                c += 1;
            }
        }
        if f == 1 || c >= 2 {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}