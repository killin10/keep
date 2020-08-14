fn main() {
    let width = 30;
    let height = 50;

    println!("The area of the rectangle is {} square pixels.", area_plain(width, height));

    println!("The area of the rectangle is {} square pixels.", area_tuple((width, height)));

    println!("The area of the rectangle is {} square pixels.", area_struct(&Rectangle{
        width,
        height
    }));

    // area
    let rect1 = Rectangle{
        width: 20,
        height: 30,
    };
    println!("The area of the rectangle is {} square pixels.", rect1.area());

    // can_hold
    let rect1 = Rectangle {
        width: 20,
        height: 50,
    };
    let rect2 = Rectangle {
        width: 10,
        height: 40,
    };
    let rect3 = Rectangle {
        width: 10,
        height: 60,
    };
    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
    println!("Can rect1 hold rect3? {}", rect1.can_hold(&rect3));

    let square = Rectangle::square(5);
    println!("Square is {:#?}", square);
}

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }

    fn square(size: u32) -> Rectangle {
        Rectangle {width: size, height: size}
    }
}

fn area_struct(rectangle: &Rectangle) -> u32 {
    println!("rectangle is {:?}", rectangle);
    println!("rectangle is {:#?}", rectangle);
    rectangle.width * rectangle.height
}

fn area_tuple(dimensions: (u32, u32)) -> u32 {
    dimensions.0 * dimensions.1
}

fn area_plain(width: u32, height: u32) -> u32 {
    width * height
}
