/*
 * Binary_tree.h
 *      Author: TanXiao
 */

#ifndef SRC_BINARY_TREE_H_
#define SRC_BINARY_TREE_H_

#include <iostream>
#include <iomanip>
#include <queue>

using std::ostream;
using std::cout;

// use a struct to store a node

struct Binary_node {
    // data members :
    int _data;
    // the node at the stage
    int _stage;
    // if the node is empty, this variable is true
    bool left_empty, right_empty;
    Binary_node *_left;
    Binary_node *_right;
    // constructors :
    Binary_node(int data = -1, bool le = 0, bool re = 0, Binary_node *father = NULL);
};

class Binary_tree {
    public:
    Binary_tree();
    bool empty() const;
    void preorder(Binary_node *sub_root, void (*visit)(int &in));
    void inorder(Binary_node *sub_root, void (*visit)(int &in));
    void posorder(Binary_node *sub_root, void (*visit)(int &in));
    void insert(int in);
    void output();
    void change();
    void getmaxheight(int &in);
    protected:
    Binary_node *_root;
    int _maxheight = 0;
    void recursive_output(Binary_node *in);
    void recursive_change(Binary_node *in);
    int getstage(Binary_node *in);
};

#endif /* SRC_BINARY_TREE_H_ */
