use std::any::type_name;

fn test_type<T>(_: T) {
    println!("{:?}", { type_name::<T>() })
}

fn main() {
    println!("Hello, World!!");
    println!("Hello, world!");
    let a:u8 = 2u8.pow(7);
    println!("a = {}", a);
    
    let tup: (i32, f64, u8, bool, &str) = (500, 3.2, 1, false, "Hello World");
    println!("{:?}", tup);
    println!("{}, {}", tup.0, tup.4);

    //typeof
    test_type(tup);
    test_type(tup.4);
}
