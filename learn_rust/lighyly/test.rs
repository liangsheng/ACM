
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

    let n = scan.next::<i32>();
    let a = (0..n).map(|_| scan.next::<i32>()).collect::<Vec<_>>();
    writeln!(out, "{}, {:?}", n, a).ok();

    let upper = 1000;

    let sum_of_squared_odd_numbers: u32 = (0..)
        .map(|n| n * n)
        .take_while(|n_squared| n_squared < &upper)
        .filter(|&n_squared| n_squared % 2 == 1)
        .fold(0, |acc, n_squared| acc + n_squared);

    println!("functional style: {}", sum_of_squared_odd_numbers);

    // test array.iter().enumerate()
    // https://blog.csdn.net/hbuxiaofei/article/details/122944029
    let a = vec!['1', '2', '3', '4'];
    for (i, &x) in a.iter().enumerate() {
        writeln!(out, "{}, {}", i, x).ok();
    }
    let ans = a.iter().enumerate().filter(|it| it.0 % 2 == 0).filter(|it| *(it.1) == '1').count();
    writeln!(out, "ans is {}", ans).ok();

    // let a = [0, 1, 2];

    // let mut iter = a.iter().map(|x| x * 2);
    // assert_eq!(iter.next(), Some(0));

    // let mut iter = a.iter().filter(|x| **x > 1);  // 需要两个 *s!
    // assert_eq!(iter.next(), Some(&2));

    // let mut iter = a.iter().take_while(|x| **x < 0); // need two *s!
    // assert_eq!(iter.next(), Some(&-1));

    // let v = [1, 2, 3];
    // let mut iter = v.into_iter();
    // assert_eq!(iter.next(), Some(&1));
    // assert_eq!(iter.next(), None);
}