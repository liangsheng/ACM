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
        for _i in 0..n {
            let x = scan.next::<i32>();
            if x > 0 {
                ans += 1;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}