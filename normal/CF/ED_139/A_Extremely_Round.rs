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

    let mut a = vec![1_i32; 1000000];
    for i in 2..1000000 {
        let mut d = i;
        let mut cnt = 0;
        while d != 0 {
            if d % 10 != 0 {
                cnt += 1;
            }
            d /= 10;
        }
        a[i] = a[i - 1];
        if cnt == 1 {
            a[i] += 1;
        }
    }
    for _ in 0..scan.next::<usize>() {
        let n = scan.next::<usize>();
        writeln!(out, "{}", a[n]).ok();
    }
}