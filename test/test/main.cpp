//
//  main.cpp
//  test
//
//  Created by Tyrone Hou on 11/20/20.
//  Copyright © 2020 Tyrone Hou. All rights reserved.
//

#include <iostream>
#include <vector>
#include "BIT.h"
#include "segmentTree.h"
using namespace std;


int main(int argc, const char * argv[]) {
    
    // for BIT
    vector<int> vec = {1,2,3,4,5,6};
//    BIT<int> bit(vec);
//
//    for(int i=0;i<vec.size();i++)
//    {
//        bit.update(i+1, vec[i]);     // note the index
//    }
//
//    cout<<"sum of first 2: "<<bit.query(2)<<endl;
//    cout<<"sum of first 4: "<<bit.query(4)<<endl;
//    cout<<"sum of index [0, 5]: "<<bit.query(1, 6)<<endl;
//    cout<<"sum of index [1, 4]: "<<bit.query(2, 5)<<endl;
//
//    // update the input vec, here we want to add 3 to 3(rd)
//    bit.update(2+1, 3);
//    cout<<"After change..."<<endl;
//    cout<<"sum of first 2: "<<bit.query(2)<<endl;
//    cout<<"sum of first 4: "<<bit.query(4)<<endl;
//    cout<<"sum of index [0, 5]: "<<bit.query(1, 6)<<endl;
//    cout<<"sum of index [1, 4]: "<<bit.query(2, 5)<<endl;
    
    
    
    // for segment tree
    vector<int> vec2 = {1,2,3,4,5,6, 7,8};
    segmentTree<int> segTree(vec2);

    cout<<"sum of [2,4]: "<<segTree.getSum(2,4)<<endl;
    cout<<"sum of [2,6]: "<<segTree.getSum(2,6)<<endl;
    
    segTree.update(3, 5);
    cout<<"After change..."<<endl;
    cout<<"sum of [2,4]: "<<segTree.getSum(2,4)<<endl;
    cout<<"sum of [2,6]: "<<segTree.getSum(2,6)<<endl;
    
    
    return 0;
}
