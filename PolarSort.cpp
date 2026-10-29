#include <bits/stdc++.h>
using namespace std;

void polarSort(vector<pair<int, int>>& p) {
    sort(p.begin(), p.end(), [](const auto& a, const auto& b) {
        return atan2(a.second, a.first) < atan2(b.second, b.first);
    });
}
/*
使用例
vector<pair<int, int>> p = {
    {0, 1}, {1, 0}, {-1, 0}, {0, -1}
};

polarSort(p);

// 偏角の小さい順(-π~π)：
// {-1, 0}, {0, -1}, {1, 0}, {0, 1}
*/