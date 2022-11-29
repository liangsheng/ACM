#[allow(unused_imports)]
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
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    let n: usize = scan.next();
    let a: Vec<i32> = (0..n).map(|_| scan.next()).collect();

    let mut dp = vec![0, 0];
    for i in 1..=n {
        let t = dp[a[i - 1] as usize] + 1;
        dp.push(t);
        dp.push(t);
    }
    for i in 1..(2 * n + 2) {
        // println!("{}", dp[i]);            // 639ms
        writeln!(out, "{}", dp[i]).ok();  // 62ms
    }
    // let dp = (&dp[1..(2 * n + 2)]).into_iter().map(|i| i.to_string()).collect::<Vec<_>>();
    // writeln!(out, "{}", dp.join("\n")).ok();
    println!("{}", dp.iter().join(" "));
}