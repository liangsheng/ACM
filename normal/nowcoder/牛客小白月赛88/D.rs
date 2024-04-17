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

    let m = scan.next::<usize>();
    let n = scan.next::<usize>();
    let d = m as i32;
    let a = (0..n).map(|_| scan.next::<i32>()).collect::<Vec<_>>();
    let mut dp = vec![vec![0; m]; 2];
    let mut now: usize = 0;
    let mut pre: usize = 1;
    dp[now][0] = 1;
    for i in 0..n {
        now ^= 1;
        pre ^= 1;
        for j in 0..m {
            dp[now][j] = 0;
        }
        for j in 0..m {
            let x = ((j as i32) + a[i]) % d;
            let y = (((j as i32) - a[i]) % d + d) % d;
            dp[now][j] = dp[pre][x as usize] | dp[pre][y as usize];
        }
    }
    if dp[now][0] == 1 {
        writeln!(out, "YES").ok();
    } else {
        writeln!(out, "NO").ok();
    }
}