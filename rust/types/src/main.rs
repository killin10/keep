fn main() {
    tuple_example();
    array_example();
}

fn tuple_example() {
    let tup: (i32, f64, u8) = (500, 6.4, 1);

    let (_x, y, _z) = tup;

    println!("The value of y is: {}", y);

    println!("The value of the third element is: {}", tup.2);
}

fn array_example() {
    let a = [1, 2, 3, 4];

    let element = a[2];
    println!("The value of the third element of array is: {}", element);
}