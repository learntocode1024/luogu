// luogu/P1308.cpp
// https://www.luogu.com.cn/problem/P1308
// Created by learntocode1024 on 2020/8/3.
//

#include <iostream>
using namespace std;

int main() {
    string target, curr;
    int cnt = 0, pos = 0, flag = 0;
    cin >> target;
    while (cin >> curr) {
        if (target == curr) {
            ++cnt;
            flag = 1;
        }
        if (flag == 0) {
            pos += curr.size();
            ++pos;
        }
    }
    if (cnt == 0) {
        printf("-1");
        return 0;
    }
    printf("%d %d", cnt,pos);
    return 0;
}