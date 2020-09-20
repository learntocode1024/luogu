// luogu/P1169_dp.cpp
// https://www.luogu.com.cn/problem/P1169
// Created by learntocode1024 on Sep 18 2020.
// 
#include <cstdio>
// #define MX 2005
#define MX 3

struct pt {
    int x = 1;
    int y = 1;
    int sqr() {
        if (x < y) return x * x;
        return y * y;
    }
    int area() {
        return x * y;
    }
};

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

bool map[MX][MX];
pt dp[MX][MX]; // n * m
int ans1, ans2, m, n;

void update(int x, int y) {
    ans1 = max(ans1, dp[x][y].sqr());
    ans2 = max(ans2, dp[x][y].area());
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", map[i] + j);
            // get x
            if (!i || !map[i - 1][j] ^ map[i][j]) dp[i][j].x = 1;
            else dp[i][j].x = dp[i - 1][j].x + 1;
            if (!j || !map[i][j - 1] ^ map[i][j]) dp[i][j].y = 1;
            else dp[i][j].y = dp[i][j - 1].y + 1;
            update(i, j);
        }
    }
    printf("%d\n%d", ans1, ans2);
    return 0;
}