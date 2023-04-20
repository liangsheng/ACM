use std::cmp::min;
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
    let mut n = x;
    let mut m = y;
    while n % m != 0 {
        let d = n % m;
        n = m;
        m = d;
    }
	m
}

fn get_prim(n: usize) -> (Vec<usize>, Vec<usize>) {
    let mut mp = vec![0_usize; n + 1];
    let mut p: Vec<usize> = Vec::new();
    for i in 2..=n {
        if mp[i] == 0 {
            mp[i] = i;
            p.push(i);
        }
        for t in p.iter() {
            if i * t > n {
                break;
            }
            mp[i * t] = *t;
            if i % t == 0 {
                break;
            }
        }
    }
    return (mp, p);
}

fn main() {
    let (mp, _p) = get_prim(10000000);
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    for _ in 0..scan.next::<usize>() {
        let x = scan.next::<i32>();
        let y = scan.next::<i32>();
        let d = gcd(x, y);
        if d > 1 {
            writeln!(out, "{}", 0).ok();
        } else {
            let mut a = y - x;
            if a == 1 {
                writeln!(out, "{}", -1).ok();
            } else {
                let mut ans = i32::MAX;
                while a != 1 {
                    let d = mp[a as usize] as i32;
                    ans = min(ans, (d - x % d) % d);
                    a /= d;
                }
                writeln!(out, "{}", ans).ok();
            }
        }
    }
}