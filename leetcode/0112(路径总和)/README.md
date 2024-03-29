# 题目
`https://leetcode-cn.com/problems/path-sum/`


# 思路
判断从root出发到达叶子的所有的路径中，是否存在长度等于x的

dfs到叶子，然后判断长度是否相等即可，注意回溯

```cpp
class Solution {
private:
    int tot, target;
    bool flag = false;
public:
    void dfs(TreeNode* root){
        if(flag) return;
        if(root){
            tot += root->val;
            if(root->left==nullptr && root->right==nullptr){
                if(tot == target){
                    flag = true;
                    return;
                }
            }
            dfs(root->left);
            dfs(root->right);
            tot -= root->val;
        }
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        tot = 0;
        target = targetSum;
        dfs(root);
        if(flag){
            return true;
        }
        else{
            return false;
        }
    }
};
```


新版本
```cpp
class Solution {
public:
    bool flag;
    void dfs(TreeNode* root, int target, int now){
        if(flag) return;
        if(root){
            if(root->left && root->right){
                dfs(root->left, target, now+root->val);
                dfs(root->right, target, now+root->val);
            }
            else if(root->left){
                dfs(root->left, target, now+root->val);
            }
            else if(root->right){   
                dfs(root->right, target, now+root->val);
            }
            else{
                if((now+root->val) == target){
                    flag = true;
                    return;
                }
            }            
        }
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        flag = false;
        dfs(root, targetSum, 0);
        return flag;
    }
};

```