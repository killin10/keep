use std::ops::Deref;

struct MyBox<T>(T);

impl <T> MyBox<T> {
    pub fn new(val: T) -> MyBox<T> {
        MyBox(val)
    }
}

impl <T> Deref for MyBox<T> {
    type Target = T;

    fn deref(& self) -> &T {
        &self.0
    }
}

fn hello(name: &str) {
    println!("Hello {}!", name);
}

fn main() {
    let x = 5;
    let y = MyBox::new(x);

    assert_eq!(5, x);
    assert_eq!(5, *y);
    
    hello("Rust");

    let a = String::from("Java");
    hello(&a);

    let b = MyBox::new(String::from("C++"));
    hello(&b);
}
