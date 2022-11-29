use itertools::Itertools;
use proconio::input;
use proconio::marker::Usize1;

fn main() {
    input! {
        n : usize,
        a : [Usize1; n]
    }

    let mut ans = vec![0];
    
    for a in a.into_iter() {
        ans.push(ans[a] + 1);
        ans.push(ans[a] + 1);
    }

    println!("{}", ans.iter().join("\n"));
}