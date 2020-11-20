//
//  main.cpp
//  test
//
//  Created by Tyrone Hou on 11/20/20.
//  Copyright © 2020 Tyrone Hou. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


template <class T>
class BIT {
    
private:
    
    //         index:  0  1  2  3  4  5
    // input _vector:  1  2  3  4  5
    //           vec:     1  2  3  4  5
    
    //vector<T> vec;
    vector<T> tree;
    
    int lowbit(const T& x)
    {
        return (x & (-x));
    }
    
    
public:
    BIT(vector<T> _vector)
    {
        //vec = _vector;
        tree.resize(_vector.size()+1);
    }
    
    
    //add x at vec[k]
    void update(const int& k, const T& x)
    {
        for(int pos = k;pos<tree.size();pos+=lowbit(pos))
            tree[pos] += x;
    }
    
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
    
    // query the area [a,b]
    T query(const int &a, const int &b)
    {
        return (query(b) - query(a-1));
    }
    
    
};



int main(int argc, const char * argv[]) {
    
    vector<int> vec = {1,2,3,4,5,6};
    
    BIT<int> bit(vec);
    
    for(int i=0;i<vec.size();i++)
    {
        bit.update(i+1, vec[i]);     // note the index
    }
    
    cout<<"sum of first 2: "<<bit.query(2)<<endl;
    cout<<"sum of first 4: "<<bit.query(4)<<endl;
    cout<<"sum of index [0, 5]: "<<bit.query(1, 6)<<endl;
    cout<<"sum of index [1, 4]: "<<bit.query(2, 5)<<endl;
    
    // update the input vec, here we want to add 3 to 3(rd)
    bit.update(2+1, 3);
    cout<<"After change..."<<endl;
    cout<<"sum of first 2: "<<bit.query(2)<<endl;
    cout<<"sum of first 4: "<<bit.query(4)<<endl;
    cout<<"sum of index [0, 5]: "<<bit.query(1, 6)<<endl;
    cout<<"sum of index [1, 4]: "<<bit.query(2, 5)<<endl;
    
    
    
    
    return 0;
}
