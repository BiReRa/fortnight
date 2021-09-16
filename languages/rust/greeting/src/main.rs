fn main() {
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    let (x, y, z) = tup;
    println!("x={}, y={}, z={}", x, y, z);

    let a = [1, 2, 3, 4, 5];
    let b = ["January", "February", "March"];
    let c : [i32; 5] = [1, 2, 3, 4, 5];
    let d = [3; 5];
    println!("a={:?}\nb={:?}\nc={:?}\nd={:?}", a, b, c, d);

    let first = a[0];
    let second = a[1];
    
    let mut a = [1, 2, 3, 4, 5];
    a[0] = 4;
    println!("a={:?}", a);
}
