#[derive(Debug)]

struct Rectangle {
    width: u32,
    height: u32
}

impl Rectangle {
    fn create(width: u32, height: u32) -> Rectangle {
        Rectangle { width, height }
    }

    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn wider(&self, rect: &Rectangle) -> bool {
        self.width > rect.width
    }
}

fn add(a: i32, b: i32) -> i32 {
    return a + b;
}

trait Comparable {
    fn compare(&self, object: &Self) -> i8;
}

fn max<T: Comparable>(array: &[T]) -> &T {
    let mut max_index = 0;
    let mut i = 1;
    while i < array.len() {
        if array[i].compare(&array[max_index]) > 0 {
            max_index = i;
        }
        i += 1;
    }
    &array[max_index]
}

impl Comparable for f64 {
    fn compare(&self, object: &f64) -> i8 {
        if &self > &object { 1 }
        else if &self == &object { 0 }
        else { -1 }
    }
}

fn main() {
    // 0- print
    let a = "Hello World";
    println!("print str, {0}, {1}", a, a);
    println!("print long long, {}", 31i64);
    println!("pi is {pi:>0width$}", pi=3.1415926, width=10);

    let x = 3.1415926535897932384626433832_f32;  // 3.14159274
    println!("x= {:.3}", x);

    let b = 34;
    let b = "abcd";
    println!("b= {}", b);

    let tup: (i32, f64, u8) = (500, 6.4, 1);
    println!("tup= {}", tup.0);
    
    let arr = [1, 2, 3, 4, 5];
    let arr: [i32; 5] = [1, 2, 3, 4, 5];
    let arr = [3; 5];
    println!("arr= {}", arr[0]);
    let mut arr = [1, 2, 3, 4];
    arr[0] = 4;
    println!("arr_change= {}", arr[0]);

    let x = 4;
    let y = {
        let x = 6;
        x + 1
    };
    println!("y= {}", y);

    fn five() -> i32 {
        5
    }
    println!("five= {}", five());

    println!("add(3, 4)= {}", add(3, 4));

    let a = 12;
    let b;
    if a > 0 {
        b = 1;
    } else if a < 0 {
        b = 1;
    }  else {
        b = 0;
    }
    println!("b is {}", b);

    let a = 3;
    let number = if a > 0 { 1 } else { -1 };
    println!("number 为 {}", number);

    let mut number = 1;
    while number != 4 {
        println!("{}", number);
        number += 1;
    }
    println!("EXIT");

    let a = [10, 20, 30, 40, 50];
    for i in a.iter() {
        println!("值为 : {}", i);
    }

    let a = [10, 20, 30, 40, 50];
    for i in 0..5 {
        println!("a[{}] = {}", i, a[i]);
    }

    let s = ['R', 'U', 'N', 'O', 'O', 'B'];
    let mut i = 0;
    loop {
        let ch = s[i];
        if ch == 'O' {
            break;
        }
        println!("\'{}\'", ch);
        i += 1;
    }

    let s = ['R', 'U', 'N', 'O', 'O', 'B'];
    let mut i = 0;
    let location = loop {
        let ch = s[i];
        if ch == 'O' {
            break i;
        }
        i += 1;
    };
    println!(" \'O\' 的索引为 {}", location);

    // let s1 = String::from("hello");
    // let s2 = s1; 
    // println!("{}, world!", s1); // 错误！s1 已经失效

    let s1 = String::from("hello");
    let s2 = s1.clone();
    println!("s1 = {}, s2 = {}", s1, s2);

    // let s1 = String::from("hello");
    // let s2 = &s1;
    // let s3 = s1;
    // println!("{}", s2);  // 这段程序不正确：因为 s2 租借的 s1 已经将所有权移动到 s3

    let s1 = String::from("hello");
    let mut s2 = &s1;
    let s3 = s1;
    s2 = &s3; // 重新从 s3 租借所有权
    println!("{}", s2);


    let mut s1 = String::from("run");
    // s1 是可变的

    let s2 = &mut s1;
    // s2 是可变的引用

    s2.push_str("oob");
    println!("{}", s2);

    let arr = [1, 2, 3, 4, 5];
    let part = &arr[1..3];
    for i in part.iter() {
        println!("part: {}", i);
    }

    let rect1 = Rectangle { width: 10, height: 40};
    println!("rect1: {:#?}", rect1);
    println!("rect1 area is: {}", rect1.area());

    let rect2 = Rectangle::create(100, 200);
    println!("rect2_area is: {}", rect2.area());

    let a = 5;
    if a == 5 {
        println!("a is 5");
    }

    let arr = [1.0, 3.0, 5.0, 4.0, 2.0];
    println!("maximum of arr is {}", max(&arr));
}