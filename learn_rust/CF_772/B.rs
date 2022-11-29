use std::*;

fn read_line() -> String {
    let mut line = String::new();
    // 可变引用: https://www.runoob.com/rust/rust-ownership.html
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn read_num<T: str::FromStr>() -> T {
    // unwrap(): https://www.runoob.com/rust/rust-error-handle.html
    // parse(): https://blog.csdn.net/u012067469/article/details/103516252
    read_line().trim().parse().ok().unwrap()
}

fn read_vec<T: str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    let case = read_num::<i32>();
    for _ in 0..case {
        let n = read_num::<usize>();
        let mut a = read_vec::<i32>();
        
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
        println!("{}\n{}", d, a.join(" "));
    }
}