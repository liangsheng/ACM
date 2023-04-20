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
        let a: Vec<char> = scan.next::<String>().chars().collect::<Vec<_>>();
        let mut b = [0, 0];
        let mut c = [5, 5];
        let mut ans: i32 = -1;
        for i in 0..10 {
            let id = (i % 2) as usize;
            if a[i] == '1' {
                b[id] += 1;
            }
            c[id] -= 1;
            if b[0] + c[0] < b[1] || b[1] + c[1] < b[0] {
                ans = (i + 1) as i32;
                break;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}