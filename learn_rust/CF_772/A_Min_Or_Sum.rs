use std::*;

fn read_line() -> String {
    let mut line = String::new();
    // 可变引用: https://www.runoob.com/rust/rust-ownership.html
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_num<T: str::FromStr>() -> T {
    read_line().trim().parse().ok().unwrap()
}

fn read_vec<T: str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    // unwrap(): https://www.runoob.com/rust/rust-error-handle.html
    // parse(): https://blog.csdn.net/u012067469/article/details/103516252
    let case = read_line().trim().parse().unwrap();
    for _ in 0..case {
        read_line();
        let ans = read_vec::<u32>().iter().fold(0, |acc, &x| acc | x);
        println!("{}", ans);
    }
}