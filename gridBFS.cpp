#include <bits/stdc++.h>
using namespace std;
//0-indexed
vector<vector<int>> gridBFS(const vector<string>& s, int sx, int sy) {
    int h = s.size(), w = s[0].size();
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> q;

    dist[sx][sy] = 0;
    q.push({sx, sy});

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (s[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return dist;
}

/*
使用例
int main() {
    int h = 4, w = 5;
    vector<string> s = {
        ".....",
        ".##..",
        "...#.",
        "....."
    };

    int sx = 0, sy = 0;
    vector<vector<int>> dist = gridBFS(s, sx, sy);

    cout << dist[3][4] << '\n';
}
*/
