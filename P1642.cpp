// luogu/P1642.cpp
// https://www.luogu.com.cn/problem/P1642
// Created by learntocode1024 on Sep 21 2020.
// 

#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
#define MX 5
using std::vector;
using std::max;
const float EPS = 1e-3;

int n, m;
int a[MX];
int b[MX];
float dp[MX][MX];
vector<int> adj[MX];
bool vis[MX] = {0};

void dfs(int curr) {
  vis[curr] = true;
  for (int child : adj[curr]) {
    if (!vis[child]) {
      dfs(child);
      for (int kI = n - m; kI > 0; --kI) {
        dp[curr][kI] = max(dp[curr][kI], dp[child][kI - 1] + dp[curr][1]);
      }
    }
  }
}

bool check(float mid) {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) dp[i][1] = (float)a[i] - mid*b[i];
  dfs(1);
  return dp[1][n - m] > 0;
}

int main() {
  // int
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
  }
  for (int i = 1, beg, end; i < n; ++i) {
    scanf("%d%d", &beg, &end);
    adj[beg].push_back(end);
    adj[end].push_back(beg);
  }
  // frac-programming
  float l = 0, r = 7, mid;
  while (r - l > EPS) {
    mid = l + (r - l)/2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.1f", mid);
  return 0;
}