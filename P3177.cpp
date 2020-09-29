// luogu/P3177.cpp
// https://www.luogu.com.cn/problem/P3177
// Created by learntocode1024 on 9/28/20.
//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define MX 22
const int inf = 0x3fffffff;
using std::vector;
using std::max;
using std::min;
using std::memset;

struct edge {
  int to;
  int val;
};

vector<edge> adj[MX];
int n, k;
int size[MX];
int dp[MX][MX][2]; // 2 spaces for colors
bool vis[MX] = {false};

void dfs(int curr) {
  vis[curr] = true;
  size[curr] = 1;
  for (edge child : adj[curr]) {
    if (vis[child.to]) continue;
    dfs(child.to);
    size[curr] += size[child.to];
    // dp
    // black
    for (int bk = size[curr]; bk > 0; --bk) {
      for (int kI = 0; kI < min(bk, size[child.to]); ++kI)
        dp[curr][bk][1] = max(dp[curr][bk][1],
                              dp[curr][bk - kI][1] + \
                              max(dp[child.to][kI][1] + child.val,
                                  dp[child.to][kI][0]));
    }
    // white
    for (int bk = size[curr]; bk >= 0; --bk) {
      for (int kI = 0; kI <= min(bk, size[child.to]); ++kI)
        dp[curr][bk][0] = max(dp[curr][bk][0],
                              dp[curr][bk - kI][0] +
                              max(dp[child.to][kI][1],
                                  dp[child.to][kI][0] + child.val));

    }
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int kI = 1, a, b, c; kI < n; ++kI) {
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  for (auto & kI : dp) {
    kI[0][1] = -inf;
  }
  dfs(1);
  printf("%d", max(dp[1][k][0], dp[1][k][1]));
  return 0;
}