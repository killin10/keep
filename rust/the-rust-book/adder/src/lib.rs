pub fn add_two(a: i32) -> i32 {
    a + 2
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }

    #[test]
    fn assert_demo() {
        assert!(1 == 1);
        assert!(!(1 == 2));
    }

    #[test]
    fn assert_eq_demo() {
        assert_eq!(3, super::add_two(1));
    }

    #[test]
    fn assert_ne_demo() {
        assert_ne!(2, super::add_two(1))
    }

    #[test]
    #[ignore]
    fn assert_ne_failed_demo() {
        assert_ne!(3, super::add_two(1), "The result of add_two({}) is: {}", 1, 3);
    }

    #[test]
    #[should_panic]
    fn should_panic_positive() {
        panic!("Panic here!");
    }

    #[test]
    #[ignore]
    #[should_panic]
    fn should_panic_negative() {
        println!("No panic!");
    }

    #[test]
    #[should_panic(expected = "Make panic")]
    fn should_panic_with_expected() {
        panic!("Make panic!");
    }
}
