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
#include "unionFindSet.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    /**********  BIT  **********/
   // vector<int> vec = {1,2,3,4,5,6};
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
     /**********  BIT  **********/
    
    
    
    /**********  segment tree  **********/
//    vector<int> vec2 = {1,2,3,4,5,6, 7,8};
//    segmentTree<int> segTree(vec2);
//
//    cout<<"sum of [2,4]: "<<segTree.getSum(2,4)<<endl;
//    cout<<"sum of [2,6]: "<<segTree.getSum(2,6)<<endl;
//
//    segTree.update(3, 5);
//    cout<<"After change..."<<endl;
//    cout<<"sum of [2,4]: "<<segTree.getSum(2,4)<<endl;
//    cout<<"sum of [2,6]: "<<segTree.getSum(2,6)<<endl;
    /**********  segment tree  **********/
    
    
    
    /**********  union find  **********/
    //         a                     f
    //     b         c               g
    //  d    e
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);
    
    d->parent = b;
    e->parent = b;
    b->parent = a;
    c->parent = a;
    a->parent = a;
    g->parent = f;
    f->parent = f;
    
    unionFindSet uf;
    cout<<"d and e in same set: "<<uf.isSameSet(d, e)<<endl;
    cout<<"d and f in same set: "<<uf.isSameSet(d, f)<<endl;
    
    uf.setUnion(a, f);
    cout<<"merge a and f"<<endl;
    cout<<"d and e in same set: "<<uf.isSameSet(d, e)<<endl;
    cout<<"d and f in same set: "<<uf.isSameSet(d, f)<<endl;
    
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    /**********  union find  **********/
    
    
    return 0;
}
