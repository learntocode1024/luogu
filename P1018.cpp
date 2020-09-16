// luogu/P1018.cpp
// https://www.luogu.com.cn/problem/P1018
// Created by learntocode1024 on Sep 16 2020.
// 
#include <cstdio>
#include <memory.h>
#define MX 41
#define MOD 
char num[MX];
int n, k;
int dp[MX][6];
int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", num);
    dp[1][0] = num[0] - '0';
    for (int step = 1; step <= k; ++step) {
        for (int curr = 1; curr < n; ++curr) {
            
        }
    }
    return 0;
}