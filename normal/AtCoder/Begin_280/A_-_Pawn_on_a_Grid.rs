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

    let h = scan.next::<usize>();
    let _w = scan.next::<usize>();
    let mut cnt = 0;
    for _ in 0..h {
        let s: Vec<char> = scan.next::<String>().chars().collect::<Vec<_>>();
        for it in s.iter() {
            if *it == '#' {
                cnt += 1;
            }
        }
    }
    writeln!(out, "{}", cnt).ok();
}