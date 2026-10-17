#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(const vector<vector<int>>& g, int s) {
    int n = g.size();
    vector<int> dist(n, -1);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dist[v] != -1) continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    return dist;
}
/*
使用例
int main() {
    int n = 5;
    vector<vector<int>> g(n);

    g[0] = {1, 2};
    g[1] = {0, 3};
    g[2] = {0, 3};
    g[3] = {1, 2, 4};
    g[4] = {3};

    int s = 0;
    vector<int> dist = BFS(g, s);

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    // 0 1 1 2 3
}
*/