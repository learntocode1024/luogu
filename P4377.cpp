// luogu/P4377.cpp
// https://www.luogu.com.cn/problem/P4377
// Created by learntocode1024 on 9/21/20.
// frac-programming Example
//

#include <cstdio>
#include <memory.h>
#define MX_N 255
#define MX_W 1000
#define MX_RATE 250
const float EPS = 1e-6;

int n, W;
int w[MX_N];
int t[MX_N];
float dp[MX_W]; // dp to ensure W meets the restriction

bool check(float var) { // dp check function
  memset(dp, 0, sizeof(dp));
  for (int kN = 0; kN < n; ++kN) {

  }
}

int main() {
  scanf("%d%d", &n, &W);
  for (int kI = 0; kI < n;scanf("%d%d", w + kI, t + kI), ++kI);
  // binary check
  float L = 0, R = MX_RATE, mid;
  while (R - L > EPS) {
    mid = L + (R - L)/2;
    if (check(mid)) L = mid;
    else R = mid;
  }
  int ans = (int)(L * 1e3);
  printf("%d", ans);
  return 0;
}