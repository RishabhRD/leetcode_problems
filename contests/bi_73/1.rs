impl Solution {
    pub fn most_frequent(nums: Vec<i32>, key: i32) -> i32 {
        nums.iter()
            .slice(2)
            .filter(|&v| -> first(&v) == key)
    }
}
