# Some tricks here

- BIT




## BIT(Binary Index Tree, 树状数组)
Reference: https://zhuanlan.zhihu.com/p/93795692

时间复杂度均为 O(log n)
- 单点修改：更改数组中一个元素的值
- 区间查询：查询一个区间内所有元素的和


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