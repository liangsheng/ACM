use std::cmp::{min, max};
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

fn gao(x1: f64, y1: f64, x2: f64, y2: f64, x3: f64, y3: f64, x4: f64, y4: f64) -> f64 {
    let tol = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3);
    let x5 = max(x1, x3);
    let y5 = max(y1, y3);
    let x6 = min(x2, x4);
    let y6 = min(y2, y4);
    let now = 0.0;
    if x6 > x5 && y6 > y5 {
        now = (x6 - x5) * (y6 - y5);
    }
    return now / tol;
}

fn change(x1: f64, y1: f64, x2: f64, y2: f64) -> (f64, f64, f64, f64) {
    return (min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2));
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    for _ in 0..scan.next::<usize>() {
        let x = scan.next::<f64>();
        let y = scan.next::<f64>();
        let xp = scan.next::<f64>();
        let yp = scan.next::<f64>();
        let mut ans = gao(0, 0, x, y, min(xp, 0), min(xp, 0), max(yp, 0), max(yp, 0));
        let res = gao(0, 0, x, y, min(xp, x), min(xp, x), max(yp, 0), max(yp, 0));
        ans = max(ans, res);
        let res = gao(0, 0, x, y, min(xp, 0), min(xp, 0), max(yp, y), max(yp, y));
        ans = max(ans, res);
        let res = gao(0, 0, x, y, min(xp, x), min(xp, x), max(yp, y), max(yp, y));
        ans = max(ans, res);

        writeln!(out, "{:.9}", ans).ok();
    }
}