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

    let h = scan.next::<usize>();
    let w = scan.next::<usize>();
    // 参考: https://atcoder.jp/contests/abc274/submissions/35865780
    let a: Vec<Vec<char>> = (0..h).map(|_| scan.next::<String>().chars().collect()).collect();
    
    // https://atcoder.jp/contests/abc274/submissions/35865138
    // filter 的参数是 &Self::Item, 所以这里用 *i
    // https://doc.rust-lang.org/nightly/std/iter/trait.Iterator.html#method.filter
    let ans = (0..w).map(|j| (0..h).filter(|i| a[*i][j] == '#').count());
    let ans = ans.into_iter().map(|i| i.to_string()).collect::<Vec<_>>();
    writeln!(out, "{}", ans.join(" ")).ok();
}