use std::collections::HashMap;

impl Solution {
    pub fn most_frequent(nums: Vec<i32>, key: i32) -> i32 {
        let mut freq_cnt = HashMap::new();
        let iter = nums
            .windows(2)
            .filter(|&window| window[0] == key)
            .map(|window| window[1]);
        for ele in iter {
            *freq_cnt.entry(ele).or_insert(0) += 1;
        }
        match freq_cnt.iter().max_by(|a, b| a.1.cmp(&b.1)) {
            Some(p) => *p.0,
            None => 0,
        }
    }
}
