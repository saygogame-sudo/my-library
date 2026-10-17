#include <bits/stdc++.h>
using namespace std;

struct Comb {
    using ll = long long;

    ll mod;
    vector<ll> fact, invfact;

    ll modpow(ll a, ll b) {
        ll res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    Comb(ll n, ll m) : mod(m), fact(n + 1), invfact(n + 1) {
        fact[0] = 1;
        for (ll i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }

        invfact[n] = modpow(fact[n], mod - 2);
        for (ll i = n; i >= 1; i--) {
            invfact[i - 1] = invfact[i] * i % mod;
        }
    }

    ll nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
    }
};
/*使用例
int main() {
    long long n = 1000000;
    long long r = 50000;
    long long m = 1000000007LL;

    Comb C(n, m);
    long long ans = C.nCr(n, r);

    cout << ans << '\n';
}
*/
