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

    let t = scan.next::<usize>();
    let mut a = vec![(0_i32, 0_i32); 5];
    let x = &mut a[0];
    x.0 = 1;
    writeln!(out, "{}, {:?}", t, x).ok();
    if a[0].0 == 0 {
        writeln!(out, "000").ok();
    } else {
        writeln!(out, "111").ok();
    }
}