#[allow(unused_imports)]
use std::cmp::{min,max};
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
    
    let case = scan.next::<i32>();
    for _ in 0..case {
        let n = scan.next::<usize>();
        let mut a: Vec<i32> = (0..n).map(|_| scan.next()).collect();
        
        let mut d = 0;
        for i in 1..n - 1 {
            if a[i] > a[i - 1] && a[i] > a[i + 1] {
                d += 1;
                if i + 2 < n && a[i + 2] > a[i] {
                    a[i + 1] = a[i + 2];
                } else {
                    a[i + 1] = a[i];
                }
            }
        }
        // iter: 不可变引用, &T
        // iter_mut: 可变引用, &mut T
        // into_iter: 所有权交出, 返回 T
        // https://blog.csdn.net/Ubuntu_is_best/article/details/104333307
        let a = a.into_iter().map(|i| i.to_string()).collect::<Vec<_>>();
        writeln!(out, "{}\n{}", d, a.join(" ")).ok();
    }
}