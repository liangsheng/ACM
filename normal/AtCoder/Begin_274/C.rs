use std::*;

fn read_line() -> String {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_vec<T: str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    let n: usize = read_line().trim().parse().unwrap();
    let a: Vec<i32> = read_vec();

    let mut dp = vec![0, 0];
    for i in 1..=n {
        let t = dp[a[i - 1] as usize] + 1;
        dp.push(t);
        dp.push(t);
    }
    for i in 1..(2 * n + 2) {
        println!("{}", dp[i]);
    }
}