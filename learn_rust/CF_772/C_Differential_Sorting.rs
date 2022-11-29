#[allow(unused_imports)]
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

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let case = scan.next::<i32>();
    for _ in 0..case {
        let n = scan.next::<usize>();
        let mut a: Vec<i64> = (0..n).map(|_| scan.next()).collect();

        if a.iter().skip(1).zip(&a).all(|(x, y)| x >= y) {
            writeln!(out, "{}", 0).ok();
        } else {
            if a[n - 2] > a[n - 1] {
                writeln!(out, "-1").ok();
            } else {
                let mut ans: Vec<String> = Vec::new();
                let mut flag = true;
                for i in (0..(n - 2)).rev() {
                    if a[i] > a[i + 1] {
                        if a[i + 1] - a[n - 1] > a[i + 1] {
                            // println!("i= {}, {}, {}, {}", i, a[i], a[i + 1], a[i + 2]);
                            flag = false;
                            break;
                        } else {
                            a[i] = a[i + 1] - a[n - 1];
                            ans.push(format!("{} {} {}", i + 1, i + 2, n));
                        }
                    }
                }
                if flag {
                    writeln!(out, "{}\n{}", ans.len(), ans.join("\n")).ok();
                } else {
                    writeln!(out, "-1").ok();
                }
            }

            // if a[n - 2] <= a[n - 1] && a[n - 1] >= 0 {
            //     let ans = (2..n)
            //         .rev()
            //         .map(|i| format!("{} {} {}", i - 1, i, n))
            //         .collect::<Vec<_>>();
            //     writeln!(out, "{}\n{}", n - 2, ans.join("\n")).ok();
            // } else {
            //     writeln!(out, "-1").ok();
            // }
        }
    }
}