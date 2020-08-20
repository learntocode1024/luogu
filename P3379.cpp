// luogu/P3379.cpp
// https://www.luogu.com.cn/problem/P3379
// Created by learntocode1024 on 2020/8/19
#include <cstring>
#include <cstdio>

const int MAXN = 50;
int t = -1, N, M, S;
int lg[MAXN];
int fi[MAXN];
int key[MAXN];
int nxt[MAXN];
int anc[MAXN][22];
int depth[MAXN+1];

inline void add_edge(int from, int to) {
    ++t;
    key[t] = to;
    nxt[t] = fi[from];
    fi[from] = t;
}

void dfs(int curr, int fath) {
    depth[curr] = depth[fath] + 1;
    anc[curr][0] = fath;
    for (int i = 1; i <= lg[depth[curr]]; ++i) {
        anc[curr][i] = anc[anc[curr][i - 1]][i - 1];
    }
    for (int i = fi[curr]; i != -1; i = nxt[i])
        if (key[i] != fath) dfs(key[i], curr);
}

void init() {
    memset(fi, -1, MAXN*sizeof(int));
    depth[MAXN] = -1;

    for(int i = 1; i <= N; ++i)
	  lg[i] = lg[i-1] + (1 << lg[i-1] == i);

    int from, to;
    for (int i = 1; i != N; ++i) {
        scanf("%d %d", &from, &to);
        add_edge(from, to);
        add_edge(to, from);
    }
    dfs(S, MAXN);
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        int c = a;
        a = b;
        b = c;
    }
    int delta = depth[a] - depth[b];
    int cnt = 0;
    while (delta) {
        if (delta & 1) a = anc[a][cnt];
        ++cnt;
        delta >>= 1;
    }
    if (a == b) return a;
    for (int k = lg[depth[a]] - 1; k != 0; --k) {
        if (anc[a][k] != anc[b][k])
            a = anc[a][k];
            b = anc[b][k];
    }
    return anc[a][0];
}

int main() {
    scanf("%d %d %d", &N, &M, &S);
    init();
    int a, b;
    for (int l = 0; l != N; ++l) {
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
    return 0;
}