const MAX_POINTS: u32 = 100_000;

fn main() {
    println!("max points: {}", MAX_POINTS);

    mut_vars();

    shadowing_vars();
}

fn mut_vars() {
    println!("Mutable");

    let mut x = 5;
    println!("The value of x is: {}", x);

    x = 6;
    println!("The value of x is: {}", x);
}

fn shadowing_vars() {
    println!("Shadowing");

    let x = 5;
    let x = x + 1;
    let x = x * 2;

    println!("The value of x is: {}", x);
}