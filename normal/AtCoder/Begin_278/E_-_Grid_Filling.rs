// from sansen
// https://atcoder.jp/contests/abc278/submissions/36611093

use itertools::*;
use proconio::marker::*;
use proconio::*;

#[fastout]
fn main() {
    input! {
        h: usize,
        w: usize,
        n: usize,
        x: usize,
        y: usize,
        a: [[Usize1; w]; h],
    }
    let inf = h + w;
    let ini = (inf, 0, inf, 0);
    let mut pos = vec![ini; n];
    for (i, a) in a.iter().enumerate() {
        for (j, a) in a.iter().enumerate() {
            let pos = &mut pos[*a];
            pos.0 = pos.0.min(i);
            pos.1 = pos.1.max(i);
            pos.2 = pos.2.min(j);
            pos.3 = pos.3.max(j);
        }
    }
    for k in 0..=(h - x) {
        println!(
            "{}",
            (0..=(w - y))
                .map(|l| {
                    let a = k;
                    let b = k + x - 1;
                    let c = l;
                    let d = l + y - 1;
                    pos.iter()
                        .filter(|&&p| p != ini && !(a <= p.0 && p.1 <= b && c <= p.2 && p.3 <= d))
                        .count()
                })
                .join(" ")
        );
    }
}
