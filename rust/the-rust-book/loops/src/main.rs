fn main() {
    loop_ex();
    while_ex();
    for_ex();
}

fn loop_ex() {
    println!("Loop");

    let mut x = 3;

    loop {
        println!("{}", x);
        x = x - 1;
        if x < 0 {
            break;
        }
    }
}

fn while_ex() {
    println!("While");

    let mut x = 3;

    while x >= 0 {
        println!("{}", x);
        x = x - 1;
    }
}

fn for_ex() {
    println!("For");
    
    let a = [10, 20, 30];

    for e in a.iter() {
        println!("{}", e);
    }

    for (i, e) in a.iter().enumerate() {
        println!("{} @ {}", e, i);
    }
}