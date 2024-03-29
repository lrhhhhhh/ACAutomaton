# 题目
[713. 乘积小于 K 的子数组](https://leetcode-cn.com/problems/subarray-product-less-than-k/)

# 思路
- 滑动窗口，枚举以j为结尾的窗口的乘积小于k的连续子数组的个数

```go
func numSubarrayProductLessThanK(nums []int, k int) int {
    if k == 0 {
        return 0 
    }
    n := len(nums) 
    ans := 0 
    pre := 1
    for i,j:=0,0; j<n; j++{
        pre *= nums[j]  
        for ; i<=j && pre >= k; i++ {
            pre /= nums[i] 
        }
        ans += j-i + 1 
    }
    return ans 
}
```