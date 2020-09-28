// luogu/P3177.cpp
// https://www.luogu.com.cn/problem/P3177
// Created by learntocode1024 on 9/28/20.
//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MX 2005
using std::vector;
using std::max;
using std::memset;

struct edge {
  int to;
  int val;
};

vector<edge> adj[MX];
int n, k;
int dp[MX][MX][2];
bool vis[MX] = {false};

void dfs(int curr) {
  vis[curr] = true;
  for (edge child : adj[curr]) {
    if (vis[child.to]) continue;
    dfs(child.to);
    // dp

  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int kI = 0, a, b, c; kI < n; ++kI) {
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back({b, c});
  }

  return 0;
}