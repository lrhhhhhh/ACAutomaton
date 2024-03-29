# 题目
[6093. 设计一个文本编辑器](https://leetcode.cn/problems/design-a-text-editor/)

# 题意
模拟

# 解法1 cpp list
使用一个迭代器it指向正确插入位置的下一个位置。重要的是学会使用list。。。

```cpp
class TextEditor {
public:
    list<char> lst;
    list<char>::iterator it;
    TextEditor() {
        lst.clear();
        it = lst.end();
    }
    
    void addText(string text) {        
        for(int i=0; i<text.size(); i++) {
            lst.insert(it, text[i]);
        }
    }
    
    int deleteText(int k) {
        int res = 0; 
        for(; it!=lst.begin() && res<k; ) {
            lst.erase(prev(it));           
            res++;
        } 
        return res; 
    }
    
    string cursorLeft(int k) {
        int cnt = 0;
        for(; it!=lst.begin() && cnt<k; it--) {
            cnt++;
        }
        cnt = 0;
        string res = "";
        for(auto i=it; i!=lst.begin() && cnt<10; i--) {
            res = *prev(i) + res;
            cnt++;
        }
        return res; 
    }
    
    string cursorRight(int k) {
        int cnt = 0;
        for(; it!=lst.end() && cnt<k; it++) {
            cnt++;
        }
        cnt = 0;
        string res = "";
        for(auto i=it; i!=lst.begin() && cnt<10; i--) {
            res = *prev(i) + res;
            cnt++;
        }
        return res;
    }
};
```

# 解法2，cpp string + insert()
```cpp
class TextEditor {
public:
    int idx;
    string s;
    TextEditor() {
        idx = 0;
    }
    
    void addText(string text) {
        s.insert(idx, text);
        idx += text.size();
    }
    
    int deleteText(int k) {
        int cnt = min(idx, k);
        idx -= cnt;
        s.erase(idx, cnt);
        return cnt;
    }
    
    string cursorLeft(int k) {
        int old = idx;
        idx -= k;
        if(idx < 0) {
            idx = 0;
        }
        int cnt = min(idx, 10);
        return s.substr(idx-cnt, cnt);
    }
    
    string cursorRight(int k) {
        int old = idx;
        idx += k;
        if(idx >= s.size()) {
            idx = s.size();
        }
        
        int cnt = min(idx, 10);
        return s.substr(idx-cnt, cnt);
    }
};

```



# 解法3， Go + list
Go 需要添加一个nil作为哨兵节点 

```go
type TextEditor struct {
    lst *list.List
    it *list.Element 
}


func Constructor() TextEditor {
    l := list.New()
    return TextEditor{
        lst: l,
        it: l.PushBack(nil),
    }
}


func (this *TextEditor) AddText(text string)  {
    for _, c := range text {
        this.lst.InsertBefore(c, this.it)
    }
}


func (this *TextEditor) DeleteText(k int) int {
    cnt := 0
    for cnt=0; this.it != this.lst.Front() && cnt < k; cnt++{
        j := this.it
        this.it = this.it.Prev()
        this.lst.Remove(this.it)        
        this.it = j
    }
    return cnt 
}


func (this *TextEditor) CursorLeft(k int) string {
    res := ""
    for cnt:=0; this.it != this.lst.Front() && cnt<k; cnt++{
        this.it = this.it.Prev()
    }
    for cnt, i:=0, this.it; i != this.lst.Front() && cnt<10; cnt++ {
        p := i.Prev()
        res = string(p.Value.(rune)) + res 
        i = p
    }
    return res 
}


func (this *TextEditor) CursorRight(k int) string {
    for cnt:=0; this.it != this.lst.Back() && cnt<k; cnt++ {
        this.it = this.it.Next()
    }
    res := ""
    for cnt, i:=0, this.it; i != this.lst.Front() && cnt<10; cnt++ {
        p := i.Prev()
        res = string(p.Value.(rune)) + res 
        i = p 
    }
    return res 
}
```


# 解法4，deque
```cpp
class TextEditor {
public:
    deque<char> l, r;
    TextEditor() {
        l.clear();
        r.clear();
    }

    void addText(string text) {
        for(int i=0; i<text.size(); i++) {
            l.push_back(text[i]);
        }
    }

    int deleteText(int k) {
        int backup = k;
        while(k && !l.empty()) {
            k--;
            l.pop_back();
        }
        return backup - k ;
    }

    string cursorLeft(int k) {
        while(k && !l.empty()) {
            k--;
            auto x = l.back();
            l.pop_back();
            r.push_front(x);
        }
        int d = min((int)l.size(), 10);
        return {l.end()-d, l.end()};
    }

    string cursorRight(int k) {
        while(k && !r.empty()) {
            k--;
            auto x = r.front();
            l.push_back(x);
            r.pop_front();
        }
        int d = min((int)l.size(), 10);
        return {l.end()-d, l.end()};
    }
};
```

# 解法5，python 直接暴力 （垃圾题目）
```python
class TextEditor:

    def __init__(self):
        self.s = ""
        self.idx = 0 


    def addText(self, text: str) -> None:
        this = self
        this.s = this.s[:this.idx] + text + this.s[this.idx:]
        this.idx += len(text)


    def deleteText(self, k: int) -> int:
        this = self 
        d = min(this.idx, k)
        this.s = this.s[:this.idx-d] + this.s[this.idx:] 
        this.idx -= d 
        return d 


    def cursorLeft(self, k: int) -> str:
        this = self
        this.idx = max(this.idx-k, 0)
        d = min(this.idx, 10)
        return this.s[this.idx-d:this.idx]


    def cursorRight(self, k: int) -> str:
        this = self
        this.idx = min(this.idx+k, len(this.s))
        d = min(this.idx, 10)
        return this.s[this.idx-d:this.idx]

```