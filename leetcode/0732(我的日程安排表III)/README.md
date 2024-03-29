# 题目
[732. 我的日程安排表 III](https://leetcode.cn/problems/my-calendar-iii/)

# 题意
预定`[start, end)`可能会导致日程表上的时间冲突，求每次预定后日程表上有多少冲突的日程。

# 思路
动态开点线段树 + 区间最值 
```cpp
class SegmentTree {
public:
    struct node {
       long long l, r, v, t;
       node() {
           t = EMPTY;
           v = 0;
           l = 0;
           r = 0;
       }
    };

    static const int EMPTY = 0x3f3f3f3f;
    vector<node> tree;

    SegmentTree() {
        tree.resize(2);
    }

    void pushdown(int p) {
        if(!tree[p].l) {
            tree.push_back(node());
            tree[p].l = tree.size() - 1;
        }
        if(!tree[p].r) {
            tree.push_back(node());
            tree[p].r = tree.size() - 1;
        }

        if(tree[p].t != EMPTY) {
            if(tree[tree[p].l].t != EMPTY) {
                tree[tree[p].l].t += tree[p].t;
            } else {
                tree[tree[p].l].t = tree[p].t;
            }

            if(tree[tree[p].r].t != EMPTY) {
                tree[tree[p].r].t += tree[p].t;
            } else {
                tree[tree[p].r].t = tree[p].t;
            }

            tree[tree[p].l].v += tree[p].t;
            tree[tree[p].r].v += tree[p].t;
            tree[p].t = EMPTY;
        }
    }

    void pushup(int p) {
        tree[p].v = max(tree[tree[p].l].v, tree[tree[p].r].v);
    }

    void update(int p, int a, int b, int l, int r, int x) {
        if(a<=l && r<=b) {
            if(tree[p].t != EMPTY) {
                tree[p].t += x;
            } else {
                tree[p].t = x;
            }
            tree[p].v += x;
        } else {
            int mid = (l + r) / 2;
            pushdown(p);
            if(a<=mid) update(tree[p].l, a, b, l, mid, x);
            if(mid<b) update(tree[p].r, a, b, mid+1, r, x);
            pushup(p); 
        }
    }
    
    long long query(int p, int a, int b, int l, int r) {
        if(a <= l && r <= b) {
            return tree[p].v;
        } else {
            int mid = (l + r) / 2;
            long long res = 0;
            pushdown(p);
            if(a <= mid) res = max(query(tree[p].l, a, b, l, mid), res);
            if(mid < b) res = max(query(tree[p].r, a, b, mid+1, r), res);
            pushup(p);
            return res;
        }
    }
};


class MyCalendarThree {
public:
    MyCalendarThree() {
        tree = new SegmentTree;
    }
    SegmentTree *tree;
    static const int INF = 1e9;
    
    int book(int start, int end) {
        tree->update(1, start+1, end, 1, INF+1, 1);
        return tree->tree[1].v;
    }
};

```

# 思路2，差分
```cpp
class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        ++mp[start];
        --mp[end];
        int cnt = 0;
        int res = 0;
        for(auto i = mp.begin(); i != mp.end(); i++) {
            cnt += i->second;
            res = max(res, cnt);
        }
        return res;
    }
};

```