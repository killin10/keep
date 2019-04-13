fn main() {
    let x = 3;

    if x < 0 {
        println!("LessThan 0");
    } else if x > 0 {
        println!("GreaterThan 0");
    } else {
        println!("EqualsTo 0");
    }

    let y = if x > 0 {
        1
    } else {
        -1
    };

    println!("The value of y is: {}", y);
}
