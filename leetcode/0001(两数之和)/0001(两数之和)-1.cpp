class Solution {
public:
    struct Node{
        int x, i;
        Node():x(0), i(0){}
        Node(int x, int i):x(x), i(i){}
        bool operator<(const Node &rhs)const{
            return this->x < rhs.x;
        }
    };

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<Node> vec(nums.size());
        for(int i=0; i<nums.size(); ++i){
            vec[i].x = nums[i];
            vec[i].i = i;
        }
        sort(vec.begin(), vec.end());
        
        for(int i=0; i<vec.size()-1; ++i){
            auto it = lower_bound(vec.begin()+i+1, vec.end(), Node(target-vec[i].x, 0)) - vec.begin();
            if(it!=vec.size() && vec[it].x==target-vec[i].x){
                ans.push_back(vec[i].i);
                ans.push_back(vec[it].i);
                return ans;
            }
        }
        return ans;
    }
};