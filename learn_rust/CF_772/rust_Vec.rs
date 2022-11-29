use std::*;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line
}

fn main() {

    let mut a = vec![1, 2, 3];
    // 这里相当于是 for i in a.into_iter(), 会发生 move, 所以 p16 会报错
    // for i in a {
    //     println!("i is {}", i);
    // }
    // println!("sum is {}", a.iter().sum::<i32>());
    
    // 相当于 for i in a.iter()
    for i in &a {
        println!("i is {}", i);
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

    let a: i32 = read_line().trim().parse().unwrap();
    println!("a is {}", gao(a));
}
