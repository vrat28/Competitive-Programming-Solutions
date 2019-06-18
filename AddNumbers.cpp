
// LEetcode

// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//https://leetcode.com/problems/two-sum/



class Solution {
   class func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
    
    var dict = [Int:Int]()
    
   for i in 0..<nums.count {
   
        let second  = target - nums[i]
    
    if let val = dict[second] as? Int{
      return [val,i]
    }
        dict[nums[i]] = i;
    }

        return []
    }
}

Solution.twoSum([33,23,5,9,2,4], 14)