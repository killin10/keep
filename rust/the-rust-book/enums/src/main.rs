enum IpAddr {
    V4(u8, u8, u8, u8),
    V6(String),
}

fn main() {
    let v4 = IpAddr::V4(127, 0, 0, 1);
    let v6 = IpAddr::V6("::1".to_string());

    match v4 {
        IpAddr::V4(p1, p2, p3, p4) => {
            println!("{}.{}.{}.{}", p1, p2, p3, p4);
        },
        IpAddr::V6(addr) => println!("{}", addr),
    }

    if let IpAddr::V6(addr) = v6 {
        println!("if let v6 addr: {}", addr);
    }
}
