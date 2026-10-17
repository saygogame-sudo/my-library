#include <bits/stdc++.h>
using namespace std;
//n以下の素数列挙
vector<int> primes(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> res;

    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) continue;

        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) res.push_back(i);
    }

    return res;
}