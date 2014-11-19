/*
* Binary_tree.cpp
*      Author: TanXiao
*/

#include "Binary_tree.h"

int max(int input1, int input2) {
    return (input1 >= input2) ? input1 : input2;
}

Binary_node::Binary_node(int data, bool le, bool re, Binary_node *father) {
    _left = _right = NULL;
    _data = data;
    left_empty = le;
    right_empty = re;
    if (father)
        _stage = father->_stage + 1;
    else
        _stage = 1;
}

Binary_tree::Binary_tree() {
    _root = NULL;
}

bool Binary_tree::empty() const {
    return _root == NULL;
}

void Binary_tree::preorder(Binary_node *sub_root, void(*visit)(int &in)) {
    if (sub_root == NULL)
        return;
    visit(sub_root->_data);
    inorder(_root->_left, visit);
    inorder(_root->_right, visit);
}

void Binary_tree::inorder(Binary_node *sub_root, void(*visit)(int &in)) {
    if (sub_root == NULL)
        return;
    inorder(_root->_left, visit);
    visit(sub_root->_data);
    inorder(_root->_right, visit);
}

void Binary_tree::posorder(Binary_node *sub_root, void(*visit)(int &in)) {
    if (sub_root == NULL)
        return;
    inorder(_root->_left, visit);
    inorder(_root->_right, visit);
    visit(sub_root->_data);
}

void Binary_tree::insert(int in) {
    std::queue<Binary_node *> p;
    if (empty()) {
        _root = new Binary_node(in, 0, 0, 0);
        return;
    }
    p.push(_root);
    while (!p.empty()) {
        if (p.front()->_left == NULL && !(p.front()->left_empty)) {
            if (in != -1)
                p.front()->_left = new Binary_node(in, 0, 0, p.front());
            else
                p.front()->left_empty = 1;
            return;
        } else if (p.front()->_right == NULL && !(p.front()->right_empty)) {
            if (in != -1)
                p.front()->_right = new Binary_node(in, 0, 0, p.front());
            else
                p.front()->right_empty = 1;
            return;
        }
        if (p.front()->left_empty && p.front()->right_empty) {
            p.pop();
            continue;
        } else if (p.front()->_left == NULL && p.front()->left_empty) {
            if (in != -1)
                p.front()->_right = new Binary_node(in, 0, 0, p.front());
            else
                p.front()->right_empty = 1;
            return;
        } else if (p.front()->_right == NULL && p.front()->right_empty) {
            p.push(p.front()->_left);
            p.pop();
            continue;
        }
        p.push(p.front()->_left);
        p.push(p.front()->_right);
        p.pop();
    }
}

void Binary_tree::output() {
    recursive_output(_root);
}

void Binary_tree::recursive_output(Binary_node *in) {
    if (in == NULL)
        return;
    recursive_output(in->_right);
    if (in->right_empty) {
        for (int i = 0; i < in->_stage + 1; i++)
            cout << "¡ª";
        cout << "EMPTY" << std::endl;
    }
    for (int i = 0; i < in->_stage; i++)
        cout << "¡ª";
    cout << std::setw(5) << std::left << in->_data << std::endl;
    if (in->left_empty) {
        for (int i = 0; i < in->_stage + 1; i++)
            cout << "¡ª";
        cout << "EMPTY" << std::endl;
    }
    recursive_output(in->_left);
}

int Binary_tree::getstage(Binary_node *in) {
    if (in == NULL)
        return 0;
    return max(getstage(in->_left), getstage(in->_right)) + 1;
}

void Binary_tree::change() {
    recursive_change(_root);
}

void Binary_tree::getmaxheight(int &in) {
    if (in >= _maxheight)
        _maxheight = in;
}

void Binary_tree::recursive_change(Binary_node *sub_root) {
    // preorder
    if (sub_root == NULL)
        return;
    Binary_node* temp = sub_root->_left;
    sub_root->_left = sub_root->_right;
    sub_root->_right = temp;
    bool tmpempty = sub_root->left_empty;
    sub_root->left_empty = sub_root->right_empty;
    sub_root->right_empty = tmpempty;
    recursive_change(sub_root->_left);
    recursive_change(sub_root->_right);
}
