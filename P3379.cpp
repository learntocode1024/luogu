// luogu/P3379.cpp
// https://www.luogu.com.cn/problem/P3379
// Created by learntocode1024 on 2020/8/19

struct Node {
    int key;
    Node* next = nullptr;
};


Node* Vex[500000];
Node node_pool[1000000];
unsigned t = 0;

void add_edge(int fi, int to) {
    node_pool[t].key = to;
    node_pool[t].next = Vex[fi];
    Vex[fi] = node_pool + to;

}