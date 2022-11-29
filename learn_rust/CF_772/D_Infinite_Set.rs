use std::*;
use std::convert::TryInto;
const MOD: i64 = 1000000007;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}
 
fn read_vec<T: str::FromStr>() -> Vec<T> {
    read_line()
        .split_whitespace()
        .filter_map(|i| i.parse().ok())
        .collect()
}

fn main() {
    let [_n, p]: [usize; 2] = read_vec().try_into().unwrap();

    let mut a = read_vec::<i32>();
    a.sort_unstable();
    let mut dp = vec![0i64; 32.max(p + 1)];
    while let Some(mut i) = a.pop() {
        let b = u32::BITS - i.leading_zeros();
        let mut ok = true;
        while ok && i > 1 {
            if i % 4 == 0 {
                i /= 4;
            } else if i % 2 == 1 {
                i /= 2;
            } else {
                break;
            }
            ok &= a.binary_search(&i).is_err();
        }
        if ok {
            dp[b as usize] += 1;
        }
    }
    let mut ans = dp[1];
    for i in 2..=p {
        dp[i] = (dp[i] + dp[i - 1] + dp[i - 2]) % MOD;
        ans = (ans + dp[i]) % MOD;
    }
    println!("{}", ans);
}