extern crate itertools;
use std::*;
use itertools::*;
use proconio::input;
use proconio::marker::*;

fn main() {
    input! {
        a: i32,
        h: usize,
        c: [Chars; h]
    }
    println!("a: {}, h: {}, c: {:#?}", a, h, c);

    let data = vec![1, 4, 3, 1, 4, 2, 5];
    let unique = data.iter().unique();
    
    for d in unique {
      print!("{} ", d);
    }
    
    //output: 1 4 3 2 5
}
