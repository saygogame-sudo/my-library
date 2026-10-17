#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> Dijkstra(const vector<vector<pair<int, ll>>>& g, int s) {
    int n = g.size();
    const ll INF = LLONG_MAX / 4;

    vector<ll> dist(n, INF);
    priority_queue<pair<ll, int>,
                   vector<pair<ll, int>>,
                   greater<pair<ll, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto [v, w] : g[u]) {
            if (dist[u] + w >= dist[v]) continue;

            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }

    return dist;
}
/*
使用例
int main() {
    int n = 4;
    vector<vector<pair<int, ll>>> g(n);

    g[0].push_back({1, 2});
    g[0].push_back({2, 5});
    g[1].push_back({2, 1});
    g[1].push_back({3, 4});
    g[2].push_back({3, 1});

    int s = 0;
    vector<ll> dist = Dijkstra(g, s);

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    // 0 2 3 4
}
*/