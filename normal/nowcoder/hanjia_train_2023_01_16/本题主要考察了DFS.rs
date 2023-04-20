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

    for _ in 0..scan.next::<usize>() {
        let n = scan.next::<usize>();
        let mut ans = 0;
        for _i in 0..(n * n - 1) {
            let a: Vec<char> = scan.next::<String>().chars().collect::<Vec<_>>();
            for i in 0..4 {
                if a[i] == '1' {
                    ans -= 1;
                } else if a[i] == '2' {
                    ans += 1;
                }
            }
        }
        ans = 10 - ans;
        writeln!(out, "{}", ans).ok();
    }
}