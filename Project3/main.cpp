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
        std::cout << "������:\n" << "1 : ����һ��������(Ԫ�� >= 0)\n    (ps �½�������������)\n"
        << "2 : ���һ��������\n"
        << "3 : �������������������Һ���\n"
        << "9 : ��������\n"
        << "0 : �˳�����\n";
    else if (in == "input")
        std::cout << "�밴��������£������������룬��-2��β����˽ڵ�Ϊ�գ�������-1"
                  <<"\nע�⣺�ڵ�ֻ��һ�����ʱ����һ����λ��ҲҪ����-1\n";
    else if (in == "output")
        std::cout << "���Ϊ����������ʱ��ת90�ȣ�ÿһ��������һ��\n";
    else if (in == "change")
        std::cout << "������ɣ�������Բ鿴Ч��\n";
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
