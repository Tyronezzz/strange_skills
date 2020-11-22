//
//  unionFindSet.h
//  test
//
//  Created by Tyrone Hou on 11/22/20.
//  Copyright © 2020 Tyrone Hou. All rights reserved.
//

#ifndef unionFindSet_h
#define unionFindSet_h

using namespace std;

class Node
{
public:
    Node *parent;
    int value;
    int rank;       // optimization 1
    
    Node(int v): parent(NULL), value(v), rank(0) {}
    
};

class unionFindSet
{
private:
    //vector<> parent;
    
public:
    
    void init()
    {
    }
    
    unionFindSet()
    {
        // init();
    }
    
    Node* find(Node *p)
    {
        return (p->parent == p? p: find(p->parent));
    }
    
    void setUnion(Node *p, Node *q)
    {
        Node *pParent = find(p);
        Node *qParent = find(q);
        pParent->parent = qParent;
    }
    
    bool isSameSet(Node *p, Node *q)
    {
        return (find(p) == find(q));
    }
    
    
    // dfs to get rank from root to leaves. But here we don't set child for Node, so we cannot dfs from root. One way is set child field for Node and when init, we point out the parent and child.
    void getRank(Node *root, int &rank)
    {
    }
    
    //按秩合并
    void setUnionImprove(Node *p, Node *q)
    {
        Node *pParent = find(p);
        Node *qParent = find(q);
        
        if(pParent==qParent)
            return;
        
        if(pParent->rank > qParent->rank)
            qParent->parent = pParent;
        
        else if(pParent->rank < qParent->rank)
            pParent->parent = qParent;
        
        else
        {
            qParent->parent = pParent;
            pParent->rank +=1;
        }
    }
    
    //路径压缩
    Node* findImprove(Node *p)
    {
        if(p->parent != p)
            p->parent = find(p->parent);
        return p->parent;
    }
};




#endif /* unionFindSet_h */
