# 题目分类

# dfs
|题解|描述|解法|难度|
|--|--|--|--|  
[743-网络延迟时间](./0743(网络延迟时间).md)|判有向图的连通性|dfs判连通|简单
[0017-电话号码的字母组合](./0017(电话号码的字母组合).md)|手机按键数字转字母|dfs|简单
[0022-括号生成](./0022(括号生成).md)|生成合法的括号组合|dfs|中等
[0079-单词搜索](./0079(单词搜索).md)|判断字符串是否出现在字符矩阵中|dfs+回溯|中等
[0797-所有可能的路径](./0797(所有可能的路径).md)|求从0到n-1的全部路径|dfs+回溯|中等


# bfs

# 图
|题解|描述|解法|难度|
|--|--|--|--|
[743-网络延迟时间](./0743(网络延迟时间).md)|单源最短路模板题|dijkstra|简单
[802-找到最终的安全状态](./0802(找到最终的安全状态).md)|求dfs过程中无环的所有起点|dfs+三色标记法/反图+拓扑排序|中等
[847-访问所有节点的最短路径](./0847(访问所有节点的最短路径).md)|求一条包含所有顶点的路径，要求路径最短|状态压缩BFS|中等

# 数学
|题解|描述|解法|难度|
|--|--|--|--|
[0611-有效三角形的个数](./0611(有效三角形的个数).md)|求数组中能组成三角形的三元组的个数|三角形最短两边之和大于第三边|简单
[0264-丑数II](./0264(丑数%20II).md)|求第n个丑数|递推|简单
[0313-超级丑数](./0313(超级丑数).md)|求第n个超级丑数|递推|简单
[0118-杨辉三角](./0118(杨辉三角).md)|求每一行杨辉三角形的值|找规律|简单



# 思维/脑筋急转弯
|题解|描述|解法|难度|
|--|--|--|--|
[0789-逃脱阻碍者](./0789(逃脱阻碍者).md)|x逃跑之前不被其他人追上|思维|简单



# 滑动窗口/双指针
|题解|描述|解法|难度|
|--|--|--|--|
[0209-长度最小的子数组](./0209(长度最小的子数组).md)|求最短连续的子数组，使得子数组和大于x|思维|中等
[0011-盛最多水的容器](./0011(盛最多水的容器).md)|求一个区间，使得x最大|思维/双指针|中等
[0986-区间列表的交集](./0986(区间列表的交集).md)|求两个区间数组的所有区间的交集|数学/双指针|中等
[0844-比较含退格的字符串](./0844(比较含退格的字符串).md)|对两个字符串进行编辑操作后，判断是否相等|思维/双指针|中等



# 二分/三分
|题解|描述|解法|难度|
|--|--|--|--|
[0001-两数之和](./0001(两数之和).md)|在数组中寻找和等于target的两个数的下标|二分|简单
[0034-在排序数组中查找元素的第一个和最后一个位置](./0034(在排序数组中查找元素的第一个和最后一个位置).md)|查找元素的左右区间|二分|简单 
[0033-搜索旋转排序数组](./0033(搜索旋转排序数组).md)|升序数组旋转一次后以O(logn)复杂度寻找其中元素|二分/脑经急转弯|中等
[0074-搜索二维矩阵](./0074(搜索二维矩阵).md)|在一个排好序的二维矩阵中查找元素|二分/脑经急转弯|中等
[0153-寻找旋转排序数组中的最小值](./0153(寻找旋转排序数组中的最小值).md)|在排序后旋转的数组里找最小值|二分/脑经急转弯|中等
[0162-寻找峰值](./0162-(寻找峰值).md)|寻找一个峰值|二分/脑经急转弯|中等


# 贪心
|题解|描述|解法|难度|
|--|--|--|--|
[0881-救生艇](./0881(救生艇).md)|求最少需要多少船过河|贪心|简单



# dp
|题解|描述|解法|难度|
|--|--|--|--|
[0313-超级丑数](./0313(超级丑数).md)|求第n个超级丑数|dp|中等
[0413-等差数列划分](./0413(等差数列划分).md)|求数组中等差数列个数(连续子数组)|dp|中等
[0446-等差数列划分II](./0446(等差数列划分%20II%20-%20子序列).md)|求数组中等差数列个数（非连续子数组）|dp|困难
[0516-最长回文子序列](./0516(最长回文子序列).md)|最长回文子序列|dp|中等
[0055-跳跃游戏](./0055(跳跃游戏).md)|求下标i最多跳跃A[i]下，是否能到达n|dp|中等
[0787-K站中转内最便宜的航班](./0787(K%20站中转内最便宜的航班).md)|有点数量限制的单源最短路|dp|中等
[0062-不同路径](./0062(不同路径).md)|从(0, 0)到达(m, n)的路径数|dp|简单
[0091-解码方法](./0091(解码方法).md)|带限制的字符串子串的组合个数|dp|中等
[0139-单词拆分](./0139(单词拆分).md)|判断字符串是否可被拆分为特定的单词|dp|中等
[0673-最长递增子序列的个数](./0673(最长递增子序列的个数).md)|求长为x的最长上升子序列的个数|dp|中等
[1143-最长公共子序列](./1143(最长公共子序列).md)|求两个字符串的最长公共子序列的长度|dp|中等
[0583-两个字符串的删除操作](./0583(两个字符串的删除操作).md)|求两个字符串的最长公共子序列的长度|dp|中等


# 字符串

# 树
|题解|描述|解法|难度|
|--|--|--|--|
|[0144-二叉树的前序遍历](./0144(二叉树的前序遍历).md)|树的前序遍历|朴素-前序遍历|简单|
|[0094-二叉树的中序遍历](./0094(二叉树的中序遍历).md)|树的中序遍历|朴素-中序遍历|简单|
|[0145-二叉树的后序遍历](./0145(二叉树的后序遍历).md)|树的后序遍历|朴素-后序遍历|简单|
|[0101-对称二叉树](./0101(对称二叉树).md)|判断一棵二叉树是否对称|特殊遍历|中等|
|[0104-二叉树的最大深度](./0104(二叉树的最大深度).md)|求树的最大深度|递归|简单|
|[0102-二叉树的层序遍历](./0102(二叉树的层序遍历).md)|求二叉树的每层元素|bfs|简单|
|[0226-翻转二叉树](./0226(翻转二叉树).md)|翻转二叉树|dfs|简单|
|[0112-路径总和](./0112(路径总和).md)|判断是否存在到达叶子且长度为x的路径|dfs|简单|
|[0700-二叉搜索树中的搜索](./0700(二叉搜索树中的搜索).md)|在BST中查找值为x的节点|dfs|简单|
|[0701-二叉搜索树中的插入操作](./0701(二叉搜索树中的插入操作).md)|在BST中插入值x|dfs|简单|
|[0653-两数之和IV 输入BST](./0653(两数之和%20IV%20-%20输入%20BST).md)|在BST中找到和为k的两个数|dfs|简单|
|[0235-二叉搜索树的最近公共祖先](./0235(二叉搜索树的最近公共祖先).md)|求BST上两个节点的最近公共祖先|dfs|简单|
|[0098-验证二叉搜索树](./0098(验证二叉搜索树).md)|判断一棵树是不是BST|dfs|简单|



# 其他数据结构
|题解|描述|解法|难度|
|--|--|--|--|
|[0020-有效的括号](./0020(有效的括号).md)|括号匹配|栈|简单|
|[0083-删除排序链表中的重复元素](./0083(删除排序链表中的重复元素).md)|删除链表汇总重复元素|链表|简单|
|[0206-反转链表](./0206(反转链表).md)|反转链表|链表|简单|
|[0203-移除链表元素](./0203(移除链表元素).md)|删除链表中值为x的元素|链表|简单|  
|[0021-合并两个有序链表](./0021(合并两个有序链表).md)|合并两个有序的链表为一个|链表|简单|  
|[0141-环形链表](./0141(环形链表).md)|判断链表是否有环|快慢指针|简单|  
|[0295-数据流的中位数](./0295(数据流的中位数).md)|求动态数组的中位数|大小堆维护中位数|困难|  




# 模拟
|题解|描述|解法|难度|
|--|--|--|--| 
[0457-环形数组是否存在循环](./0457(环形数组是否存在循环).md)|求按数组内容为下标进行遍历，是否能得到一个环|暴力模拟/快慢指针|中等
[0556-重塑矩阵](./0556(重塑矩阵).md)|reshape matrix|模拟|简单
[0036-有效的数独](./0036(有效的数独).md)|判断数独是否有效|模拟|简单
[0073-矩阵置零](./0073(矩阵置零).md)|以O(1)的空间复杂度将矩阵0元素所在的行和列全部置为0|模拟|中等
[0232-用栈实现队列](./0232(用栈实现队列).md)|用栈来模拟队列|模拟|中等
[0844-比较含退格的字符串](./0844(比较含退格的字符串).md)|对两个字符串进行编辑操作后，判断是否相等|模拟|中等
[0005-最长回文子串](./0005(最长回文子串).md)|求最长回文串|模拟|简单





# 简单
- [1377-矩阵中战斗力最弱的k行](./1337(矩阵中战斗力最弱的%20K%20行).cpp)
- [1137-第N个泰波那契数](./1137(第%20N%20个泰波那契数).md)
- [0350-两个数组的交集II](./0350(两个数组的交集%20II).md)
- [0121-买卖股票的最佳时机](./0121(买卖股票的最佳时机).md)
- [0387-字符串中的第一个唯一字符](./0387(字符串中的第一个唯一字符).md)
- [0383-赎金信](./0383(赎金信).md)
- [0242-有效的字母异位词](./0242(有效的字母异位词).md)
- [1646-获取生成数组中的最大值](./1646-(获取生成数组中的最大值).md)
- [1480-一维数组的动态和](./1480(一维数组的动态和).md)
- [1588-所有奇数长度子数组的和](./1588(所有奇数长度子数组的和).md)

