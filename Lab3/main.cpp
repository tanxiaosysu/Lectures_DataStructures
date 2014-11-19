/*
* main.cpp
*      Author: TanXiao
*/

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstdio>

#include "Binary_tree.h"

void print(std::string in) {
    if (in == "start")
        std::cout << "请输入:\n" << "1 : 输入一个二叉树(元素 >= 0)\n    (ps 新建二叉树需重启)\n"
        << "2 : 输出一个二叉树\n"
        << "3 : 交换二叉树的所有左右孩子\n"
        << "9 : 重启程序\n"
        << "0 : 退出程序\n";
    else if (in == "input")
        std::cout << "请按层从上至下，从左至右输入，以-2结尾，如此节点为空，则输入-1"
                  <<"\n注意：节点只有一个后代时，另一个的位置也要输入-1\n";
    else if (in == "output")
        std::cout << "输出为将二叉树逆时针转90度，每一个—代表一层\n";
    else if (in == "change")
        std::cout << "交换完成，请输出以查看效果\n";
}

void Input(Binary_tree &bt) {
    int in;
    std::cout << "$";
    while ((std::cin >> in) && (in != -2))
        bt.insert(in);
}

void Output(Binary_tree &bt) {
    bt.output();
}

int main() {
    char input;
    while (1) {
        print("start");
        Binary_tree BiTree;
        while (1) {
            bool restart = 0;
            std::cout << "$";
            input = _getche();
            std::cout << "\n";
            switch (input) {
                case '1':
                    print("input");
                    Input(BiTree);
                    break;
                case '2':
                    print("output");
                    Output(BiTree);
                    break;
                case '3':
                    BiTree.change();
                    print("change");
                    break;
                case '9':
                    restart = 1;
                    break;
                case '0':
                    return 0;
            }
            if (restart)
                break;
        }
        system("cls");
    }
    return 0;
}
