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
    let mut a: Vec<i32> = (0..n).map(|_| scan.next::<i32>()).collect::<Vec<_>>();
    let m = scan.next::<usize>();
    for _ in 0..m {
        let cmd = scan.next::<i32>();
        if cmd == 1 {
            let k = scan.next::<usize>();
            let x = scan.next::<i32>();
            a[k - 1] = x;
        } else {
            let k = scan.next::<usize>();
            writeln!(out, "{}", a[k - 1]).ok();
        }
    }
}