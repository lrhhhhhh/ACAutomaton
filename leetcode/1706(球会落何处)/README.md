# 题目
[1706. 球会落何处](https://leetcode-cn.com/problems/where-will-the-ball-fall/)

# 题意
每一列都有一个球从最高层开始掉落，求掉落到最底层的情况。

# 思路
- 上一步决定下一步往哪个方向走，每一步需要判断能否走出下一步，按这样模拟即可。
- 需要特判第一列和最后一列在最顶层时的情况

```go
func findBall(grid [][]int) []int {
    m := len(grid)
    n := len(grid[0])
    ans := make([]int, n)

    for j:=0; j<n; j++ {
        if j==0 && grid[0][0] == -1 {
            ans[j] = -1
            continue;
        }
        if j == n-1 && grid[0][n-1] == 1 {
            ans[j] = -1 
            continue;
        }

        backup := j
        for i:=0; i<m; i++ {
            if grid[i][j] == 1 && j+1 <n && grid[i][j+1] == 1 {
                j += 1
            } else if grid[i][j] == -1 && j-1 >=0 && grid[i][j-1] == -1{
                j -= 1
            } else {
                ans[backup] = -1
                break
            }
        }
        if ans[backup] != -1 {
            ans[backup] = j
        }     
        j = backup 
    }
    return ans 
}
```


