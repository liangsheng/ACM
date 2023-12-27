// #![allow(dead_code, unused_variables, dead_code, unused_mut)]
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

fn gcd(x: i32, y: i32) -> i32 {
    if y == 0 {
        return x;
    }
    return gcd(y, x % y);
}

fn lcm(x: i32, y: i32) -> i32 {
    return x * y / gcd(x, y);
}

fn gao(a: &mut Vec::<i32>, b: &mut Vec::<i32>, m: usize, k: usize) {
    let mut h: usize = 0;
    let mut e: usize = 0;
    let mut p: usize = 0;
    let mut q = vec![vec![0i32; 2]; m];
    for i in 0..(m - k + 1) {
        while p < i + k {
            while h != e && q[e - 1][0] <= b[p] {
                e -= 1;
            }
            q[e][0] = b[p];
            q[e][1] = p as i32;
            e += 1;
            p += 1;
        }
        a[i] = q[h][0];
//         println!("i= {}, {}", i, a[i]);
        while h != e && (q[h][1] as usize) <= i {
            h += 1
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    
    let n = scan.next::<usize>();
    let m = scan.next::<usize>();
    let k = scan.next::<usize>();
    let mut g = vec![vec![0; m]; n];
    for i in 0..n {
        for j in 0..m {
            g[i][j] = lcm((i + 1) as i32, (j + 1) as i32); 
        }
    }
    let mut a = vec![vec![0; m - k + 1]; n];
    for i in 0..n {
        gao(&mut a[i], &mut g[i], m, k);
    }
    let mut ans: i64 = 0;
    for j in 0..(m - k + 1) {
        let mut h: usize = 0;
        let mut e: usize = 0;
        let mut p: usize = 0;
        let mut q = vec![vec![0i32; 2]; n];
        for i in 0..(n - k + 1) {
            while p < i + k {
                while h != e && q[e - 1][0] <= a[p][j] {
                    e -= 1;
                }
                q[e][0] = a[p][j];
                q[e][1] = p as i32;
                e += 1;
                p += 1;
            }
            ans += q[h][0] as i64;
            while h != e && (q[h][1] as usize) <= i {
                h += 1
            }
        }
    }
    writeln!(out, "{}", ans).ok();
}
