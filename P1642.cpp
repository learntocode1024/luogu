// luogu/P1642.cpp
// https://www.luogu.com.cn/problem/P1642
// Created by learntocode1024 on Sep 21 2020.
// 

#include <cstdio>
#include <memory.h>
#include <list>
#define MX 100

struct factory {
  int pollution;
  int production;
  float rate() {
    return (float)production / (float)pollution;
  }
  factory operator+ (const factory &a) {
    factory ans;
    ans.pollution = pollution + a.pollution;
    ans.production = production + a.production;
    return ans;
  }
  factory operator+= (const factory &a) {
    production += a.production;
    pollution += a.pollution;
    return *this;
  }
};

int n, m;
factory map[MX];
factory dp[MX][MX];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, j; i < n; ++i) {
    scanf("%d", &j), map[i].production = j;
  }
  for (int i = 0, j; i < n; ++i) {
    scanf("%d", &j), map[i].pollution = j;
  }
  return 0;
}