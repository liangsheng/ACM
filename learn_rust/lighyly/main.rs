use std::*;
use itertools::*;
use proconio::input;
use proconio::marker::*;


fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

struct Solution {
    a: Vec<i32>
}

impl Solution {
    pub fn gao(p: usize, fa: usize, d: i32, dp: &mut Vec<i32>, g: &Vec<Vec<usize>>, nums: &Vec<i32>) -> bool {
        dp[p] = nums[p];
        for x in &g[p] {
            if *x != fa {
                if !Self::gao(*x, p, d, dp, g, nums) {
                    return false;
                } 
                dp[p] += dp[*x];
            }
        }
        if dp[p] == d {
            dp[p] = 0;
            return true;
        }
        if dp[p] > d {
            return false;
        }
        return true;
    }

    pub fn component_value(nums: Vec<i32>, edges: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let sum: i32 = nums.iter().sum();
        let mut g: Vec<Vec<usize>> = (0..n).map(|_| Vec::new()).collect();
        for it in edges {
            let x = it[0] as usize;
            let y = it[1] as usize;
            g[x].push(y);
            g[y].push(x);
        }

        let mut dp = vec![0i32; n];
        let mut d: Vec<i32> = Vec::new();
        for i in 1..n {
            if i * i >= n {
                break;
            }
            if n % i == 0 {
                d.push(i as i32);
            }
            if n / i != i {
                d.push((n / i) as i32);
            }
        }
        d.sort_unstable();
        for t in d {
            if Self::gao(0, n, t, &mut dp, &g, &nums) {
                return (n as i32) / t - 1;
                break;
            }
        }
        return 0i32;
    }
}

fn main() {

    input! {
        n: u8,
        m: u32,
        l: i32,
    }

    // now you can use n, m and l as variable.
    println!("n is {}, m is {}, l is {}", n, m, l);

    let mut a = vec![1, 2, 3];
    // 这里相当于是 for i in a.into_iter(), 会发生 move, 所以 p16 会报错
    // for i in a {
    //     println!("i is {}", i);
    // }
    // println!("sum is {}", a.iter().sum::<i32>());
    
    // 相当于 for i in a.iter()
    for i in &a {
        println!("iter, i is {}", i);
    }
    println!("sum is {}", a.iter().sum::<i32>());

    // 相当于 for i in a.iter_mut()
    for i in &mut a {
        *i += 10;
        println!("i is {}", i);
    }
    println!("sum is {}", a.iter().sum::<i32>());

    fn gao(x: i32) -> i32 {
        if x == 1 {
            return 1;
        }
        x + gao(x - 1)
    }

    let n: i32 = read_line().trim().parse().unwrap();
    println!("a is {}", gao(n));

    let mut b: Vec<Vec<i32>> = (0..n).map(|_| Vec::new()).collect();
    b[0].push(1);
    b[1].push(2);
    b[1].push(3);
    b[2].push(4);
    for i in b {
        for j in i {
            println!("b is {}", j);
        }
    }
    // println!("{:?}", b);

     let name = String::from("Rust");
     println!("before: {}", name); // before: Rust
     let greeting = hello(&name);
     println!("{}", greeting); // Hello, Rust
     println!("after: {}", name); // after: Rust

    let mut ans = vec![0i32: 10];
    println!("{}", ans.iter().join("\n"));
}

 fn hello(name: &String) -> String {
     format!("Hello, {}", name)
 }