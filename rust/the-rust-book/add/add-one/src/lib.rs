extern crate rand;

pub fn add_one(x: i32) -> i32 {
    x + 1
}

#[cfg(test)]
mod test {
    #[test]
    fn add_one() {
        assert_eq!(2, super::add_one(1));
    }
}