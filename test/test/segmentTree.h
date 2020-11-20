//
//  segmentTree.h
//  test
//
//  Created by Tyrone Hou on 11/20/20.
//  Copyright © 2020 Tyrone Hou. All rights reserved.
//

#ifndef segmentTree_h
#define segmentTree_h

using namespace std;

template <class T>
class segmentTree {
    
private:
    vector<T> tree;
    int _size;
    
    
    T merge(const T& l, const T& r)
    {
        // add
        return (l+r);
    }
    
    // [left, right)
    T sum(int l, int r)
    {
        l = l + _size;
        r = r + _size;
        T sum = 0;
        
        while(l < r)
        {
            if( (l&1) == 1)       // range left is odd
            {
                sum += tree[l];
                l++;
            }
            
            if( (r&1) == 1)
            {
                r--;
                sum += tree[r];
            }
            
            l >>= 1;
            r >>= 1;
        }
        
        return sum;
    }
    
    
public:
    
    segmentTree(vector<T> _vec)
    {
        int n = _vec.size();
        _size = n;
        tree.resize(n*2);
        
        
        for(int i=n;i<2*n;i++)
        {
            tree[i] = _vec[i-n];     // build the leaves from left to right
        }
        
        for(int i=n-1;i>=0;i--)
        {
            tree[i] = merge(tree[2*i], tree[2*i+1]);       // build the inner node, bottom to up
        }
    }
    
    // update input vector, vec[i] = x. Then update tree
    void update(const int& i, const int& x)
    {
        int pos = i + _size;
        tree[pos] = x;
        
        while(pos>1)
        {
            pos /= 2;
            tree[pos] = merge(tree[2*pos], tree[2*pos+1]);
        }
    }
    
    // calculate the sum
    T getSum(int l, int r)
    {
        return sum(l, r+1);     // [left, right)
    }
    
    
    void outPrint()
    {
        for(int x:tree)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    
};



#endif /* segmentTree_h */
