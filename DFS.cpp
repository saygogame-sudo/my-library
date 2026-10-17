#include <bits/stdc++.h>
using namespace std;

void DFS(const vector<vector<int>>& g, int u, vector<int>& seen) {
    seen[u] = 1;

    for (int v : g[u]) {
        if (seen[v]) continue;
        DFS(g, v, seen);
    }
}
/*
到達可能性
使用例
int n = g.size();
vector<int> seen(n, 0);
DFS(g, s, seen); 
*/

void DFSorder(const vector<vector<int>>& g, int u,
    vector<int>& seen, vector<int>& order) {
seen[u] = 1;
order.push_back(u);

for (int v : g[u]) {
if (seen[v]) continue;
DFSorder(g, v, seen, order);
}
}

/*
行きがけ順
使用例
vector<int> seen(g.size(), 0);
vector<int> order;
DFSorder(g, s, seen, order);
*/

void DFSpost(const vector<vector<int>>& g, int u,vector<int>& seen, vector<int>& post) {
seen[u] = 1;

for (int v : g[u]) {
if (seen[v]) continue;
DFSpost(g, v, seen, post);
}

post.push_back(u);
}

/*
帰りがけ順(トポロジカルソート)
使用例
vector<int> seen(g.size(), 0);
vector<int> post;
DFSpost(g, s, seen, post);
*/

void DFSparent(const vector<vector<int>>& g, int u,
    vector<int>& seen, vector<int>& parent) {
seen[u] = 1;

for (int v : g[u]) {
if (seen[v]) continue;

parent[v] = u;
DFSparent(g, v, seen, parent);
}
}

/*
親頂点
使用例
vector<int> seen(g.size(), 0);
vector<int> parent(g.size(), -1);
DFSparent(g, s, seen, parent);
*/