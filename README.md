# Some tricks here

- BIT
- Segment tree



## BIT(Binary Index Tree, 树状数组)

### Reference
https://zhuanlan.zhihu.com/p/93795692




时间复杂度均为 O(log n)
- 单点修改：更改数组中一个元素的值
- 区间查询：查询一个区间内所有元素的和



![image_bit](https://github.com/Tyronezzz/strange_skills/blob/master/images/bit.png)


我们定义：二进制数x最右边的一个1，连带着它之后的0为lowbit(x)。那么
```
lowbit(x) = x & (-x);
// e.g   x = 0x1010, -x = 0x10, lowbit(x) = 0x10;
```

单点修改
```
vector<int> vec(size, 0);     // original vector
vector<int> tree(size+1, 0);

//在原数组[k]处加x
void update(int k, const int& x)
{
    for(int pos = k;pos<tree.size();pos+=lowbit(pos))
        tree[pos] += x;
}
```

求前n项和
```
// query the first k of vec
    T query(const int& k)
    {
        T sum = 0;
        for(int pos = k;pos>0;pos-=lowbit(pos))
        {
            sum += tree[pos];
        }
        return sum;
    }
```

区间查询
```
    // query the area [a,b]
    T query(const int &a, const int &b)
    {
        return (query(b) - query(a-1));
    }
```




## Segment tree(线段树)

### Reference
https://zhuanlan.zhihu.com/p/93795692
https://www.jianshu.com/p/6fd130084a43

时间复杂度均为 O(log n)
- 单点修改：更改数组中一个元素的值
- 区间查询：查询一个区间内所有元素的和
- 查询区间最大值，区间最小值


### 构造
给定一个数组vec，长度为n，我们构造一个新数组tree，
1. 使得[n, 2 * n-1]（0 index）为叶节点，tree[n, 2 * n-1] = vec[0, n-1]。
2. tree[1,n-1]为父节点，对每一个父节点i，left = 2 * i, right = 2 * i+1; 

### 更新
更新当前节点值，并自底向上更新父节点
*tree的索引从1开始*


### 查询（求和，求极值）

[left, right)



### 区间更新？？？



