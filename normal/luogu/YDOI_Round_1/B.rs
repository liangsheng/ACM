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
    let t = scan.next::<u32>();

    let mut a = (0..n).map(|_| scan.next::<u32>()).collect::<Vec<_>>();
    a.sort();

    let mut b = vec![0u64; n + 1];
    for i in 1..=n {
        b[i] = b[i - 1] + (a[i - 1] as u64);
    }

    // https://blog.csdn.net/qq_21484461/article/details/131649205
    let ok = |mid: u64| {
        // upper_bound
        let id = a.partition_point(|x| (*x as u64) <= mid);
        let tmp = b[id] + mid * ((n - id) as u64);
        // println!("tmp= {}", tmp);
        return tmp >= mid * (t as u64);
    };

    let mut l: u64 = 1;
    let mut r: u64 = b[n] / (t as u64);
    // for _i in 0..4 {
    while l != r {
        let mid = (l + r) / 2 + 1;  // 求最大值这里要 +1
        // println!("l= {}, r= {}, mid= {}, ok= {}", l, r, mid, ok(mid));
        if ok(mid) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    writeln!(out, "{}", l).ok();
}

// https://blog.51cto.com/seekstar/5756989
// fn main() {
//     let a = [1, 2, 3, 3, 4];
//     // lower_bound
//     println!("{}", a.partition_point(|x| *x < 3));
//     // upper_bound
//     println!("{}", a.partition_point(|x| *x <= 3));
// }