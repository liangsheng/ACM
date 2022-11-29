fn main() {
    let a = [-1, 0, 1];

    let mut iter = a.iter().take_while(|x| **x < 0); // need two *s!
    
    assert_eq!(iter.next(), Some(&-1));
    assert_eq!(iter.next(), None);

    let mut iter = a.iter();
    assert_eq!(iter.next(), Some(&-1));

    let mut iter = a.iter().map(|x| *x * 2);
    assert_eq!(iter.next(), Some(-2));    
}