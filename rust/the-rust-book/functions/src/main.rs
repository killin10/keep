fn main() {
    let x = times(3, -1);
    println!("The value of x is: {}", x);

    let x = times(3, 3);
    println!("The value of x is: {}", x);
}

fn times(value: i32, times: i32) -> i32 {
    if times < 0 {
        println!("Return");
        return value * times;
    }

    value * times
}