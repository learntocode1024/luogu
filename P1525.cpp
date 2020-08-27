// luogu/P1525.cpp
// https://www.luogu.com.cn/problem/P1525
// Created by learntocode1024 on Wed Aug 26 2020.
//

#include <cstdio>
#include <cstring>
typedef int ch;

// const int MXN = 2e4 + 5;
// const int MXM = 2e5 + 5;
const int MXN = 10 + 5;
const int MXM = 20 + 5;

struct edge {
    int key = -1;
    int w;
    int nxt;
    edge next() const;
};

int node[MXN];
bool b = true;
ch visit[MXN];
edge adj[MXM];
int N, M, mid;

edge edge::next() const {
    return adj[nxt];
};

void dfs(int curr, ch color) {
    if (!b) return;
    printf("curr %d ", curr);
    visit[curr] = color;
    for (edge j = adj[node[curr]]; j.nxt != -1; j = j.next()) {
        if (j.w >= mid) {
            if (!visit[j.key]) printf("to %d ", j.key), dfs(j.key, 3 - color);
            else if (visit[j.key] == color) {
                printf("break %d ", j.key);
                b = false;
                return;
            }
        }
    }
    printf(" done ");
}

bool judge() {
    b = true;
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= N && b; ++i) {
        printf("| judge %d : ", i);
        if (!visit[i]) dfs(i, 1);
    }
    return b;
}

int main() {
    // input
    setbuf(stdout, NULL);
    int mx_w = 0;
    scanf("%d %d", &N, &M);
    memset(node, -1, sizeof(node));
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
        mid = lo + (hi - lo >> 1);
        printf("mid = %d ", mid);
        if (judge()) hi = mid;
        else  lo = mid + 1;
        printf("\n==================\n");
    }
    printf("%d", lo);
    return 0;
}-