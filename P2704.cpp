// luogu/P2704.cpp
// https://www.luogu.com.cn/problem/P2704
// Created by learntocode1024 on 9/26/20.
//
#include <vector>
#include <cstdio>
#define MX 155
using std::vector;
int n, p;
vector<int> adj[MX];
int dp[MX][MX];
int main() {
  scanf("%d%d", &n, &p);
  for (int kI = 1, fr, to; kI < n; ++kI) {
    scanf("%d%d", &fr, &to);
    adj[fr].push_back(to);
    adj[to].push_back(fr);
  }

  return 0;
}