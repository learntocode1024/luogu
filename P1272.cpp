// luogu/P2704.cpp
// https://www.luogu.com.cn/problem/P1272
// Created by learntocode1024 on 9/26/20.
//
#include <vector>
#include <cstring>
#include <cstdio>
#define MX 155
const int inf = 0x7FFF;
using std::memset;
using std::vector;
int n, p;
vector<int> adj[MX];
int size[MX];
bool vis[MX];
int dp[MX][MX];

int min(const int &a, const int &b) {
  if (a > b) return b;
  return a;
}

void init() {
  memset(vis, 0, sizeof(vis));
  memset(dp, 0x7F, sizeof(dp));
  for (int i = 1; 1 <= n; ++i)
    dp[i][0] = 0;
}

void dfs(int curr) {
  vis[curr] = true;
  size[curr] = 1;
  for (int child : adj[curr]) {
    if (vis[child]) continue;
    dfs(child);
    size[curr] += size[child];
    // dp
    for (int cut = 1; cut < size[curr]; ++cut) {
      
    }
  }
}

int main() {
  scanf("%d%d", &n, &p);
  for (int kI = 1, fr, to; kI < n; ++kI) {
    scanf("%d%d", &fr, &to);
    adj[fr].push_back(to);
    adj[to].push_back(fr);
  }
  init();
  dfs(1);
  int ans = inf;
  for (int kJ = 1; kJ <= n; ++kJ) {
    ans = min(ans, dp[kJ][size[kJ] - p]);
  }
  printf("%d", ans);
  return 0;
}