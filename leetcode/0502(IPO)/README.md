# 题目
`https://leetcode-cn.com/problems/ipo/`


# 思路
明确题意：
- 资本=初始资本+每次利润
- 可开展项目的意思是`当前资本>=该项目的花费`

维护两个优先队列，其中：
- 优先队列pq，按利润大的优先，利润相同则花费小的优先
- 优先队列bc，按花费小的优先，花费相同则利润高的优先

维护当前资本w，每次选择利润最高的项目（要求当前资本>=该项目的花费），不满足条件的放入bc。
每更新一次w，则相应的把bc中满足条件的取出来放入pq

时间复杂度：
- 初始化优先队列O(nlogn)
- 主算法部分的时间复杂度我也不知道怎么算



```cpp
class Solution {
public:
    struct Node{
        int p, c;
        Node(int p, int c):p(p), c(c){}

        bool operator<(const Node& rhs)const{
            if(this->p < rhs.p) return true;
            else if(this->p == rhs.p) return this->p < rhs.p;
            else return false;
        }
    };
    
    class cmp{
        public:
            bool operator()(const Node& lhs, const Node& rhs){
                if(lhs.c > rhs.c) return true;
                else if(lhs.c == rhs.c) return lhs.p < rhs.p;
                else return false;
            }
    };

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); 
        priority_queue<Node> pq;
        priority_queue<Node, vector<Node>, cmp> bc;
        for(int i=0; i<n; ++i){
            pq.emplace(profits[i], capital[i]);
        }

        for(int i=0; i<k; ++i){
            while(!pq.empty()){
                Node tp = pq.top(); 
                pq.pop();
                if(tp.c <= w){
                    w += tp.p;
                    break;
                }
                else{                
                    bc.push(tp);
                }
            }
            while(!bc.empty()){
                Node tp = bc.top();
                if(tp.c <= w){
                    bc.pop();
                    pq.push(tp);
                }
                else{
                    break;
                }
            }        
        }
        return w;
    }
};
```