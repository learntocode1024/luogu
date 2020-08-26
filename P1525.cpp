// luogu/P1525.cpp
// https://www.luogu.com.cn/problem/P1525.cpp
// Created by learntocode1024 on Wed Aug 26 2020.
// 
#include <cstdio>
#include <cstring>
const int MXM = 2e4 + 5;
const int MXN = 1e5 + 5;

struct edge {
    int key = -1;
    int w;
    int nxt;
    edge next() const {
        return adj[nxt];
    };
};

int node[MXN];
char color[MXN];
edge adj[MXM << 1];
int N, M, mid;

int dfs(int curr) {
    
}

int judge(int key) {

}

int main() {
    // input
    int mx_w = 0;
    scanf("%d %d", &N, &M);
    memset(adj, -1, sizeof(adj));
    for (int i = 0, fi, to, w; i != (M << 1);) {
        scanf("%d %d %d", &fi, &to, &w);
        if (w > mx_w) mx_w = w;
        adj[i].nxt = node[fi];
        adj[i].key = to;
        adj[i].w = w;
        node[fi] = i;
        ++i;
        adj[i].nxt = node[to];
        adj[i].key = fi;
        adj[i].w = w;
        node[to] = i;
        ++i;
    }
    int lo = 0, hi = mx_w;
    while (lo < hi) {
        mid = lo + (hi - lo) >> 1;
        if (judge(mid)) hi = mid;
        else  lo = mid + 1;
    }
    printf("%d", lo);
    return 0;
}